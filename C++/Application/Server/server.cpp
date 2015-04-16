#include "server.hpp"

QMap<QUuid , ClientData*> SNZ_Server::mClients;

SNZ_Server::SNZ_Server() : protocoleManager(), running(false), mMessageDispatcher(NULL) {
  SimpleTcpStartPoint::Options options;
  options.connectionPort = 3000;
  options.cbDisconnect = OnDisconnect;
  options.maximumConnectedClients = 1;
  mSocketServer = new SimpleTcpStartPoint( options );
}

SNZ_Server::~SNZ_Server() {
  if(this->isRunning()) {
    this->stopServer();
  }
  delete(mSocketServer);
}

void SNZ_Server::start() {
  if(this->isRunning()) {
    std::cerr << "serveur is already running , abort \n";
    return;
  }
  if(!this->mSocketServer->start()) {
    std::cerr << "impossible to start socketserver \n";
    return;
  }

  this->running = true;
  pthread_t main_thread;
  pthread_create ( &(main_thread), NULL, serveur_listening_routine, this);
  pthread_detach(main_thread);
}

bool SNZ_Server::isRunning() const {
  return this->running;
}

void SNZ_Server::onReceiveMessage(QUuid client) const {
    ByteBuffer* message = NULL;
    mClients [ client ]->recv_buffering.get(message);
    if(this->mMessageDispatcher != NULL) {
        mMessageDispatcher->dispatchMessage(this->getMessage(*message));
    }
    if(message != NULL) {
        delete message;
    }
}

void SNZ_Server::stopServer() {
  if(this->isRunning()) {
    this->mSocketServer->stop();
  }
  this->running = false;
}

void SNZ_Server::acceptClient(QUuid client) {
    std::cout << "Client " << client.toString().toStdString() << " has connected!!" << std::endl;
    ClientData* clt_data  = new ClientData;
    clt_data->uuid        = client;
    clt_data->server      = this;
    clt_data->recv_buffering.mGettingReleaseBuffer = true;
    clt_data->send_buffering.mGettingReleaseBuffer = true;
    clt_data->closeMe     = false;
    pthread_create ( &(clt_data->recv_thread), NULL, client_thread_receive, clt_data );
    pthread_create ( &(clt_data->send_thread), NULL, client_thread_send, clt_data );
    mClients[ client ]     = clt_data;
}

SimpleTcpStartPoint* SNZ_Server::getSocketServer() {
    return this->mSocketServer;
}

void *serveur_listening_routine(void* data) {
  SNZ_Server *server = (SNZ_Server *) data;
  QUuid fake, client;
  while(server->isRunning()) {
    client = server->mSocketServer->listen();
    if(client != fake) {
      server->acceptClient(client);
    }
    pthread_yield();
  }
  return NULL;
}

void *client_thread_receive ( void* data)
{
    ClientData* client = (ClientData*) data;
    SimpleTcpStartPoint *socket_server = client->server->getSocketServer();
    ByteBuffer* message = new ByteBuffer;
    while ( ! client->closeMe ) {
      if ( socket_server->dataAvailable(client->uuid)) {
            socket_server->receive(client->uuid,*message);
        }
        if ( message->getLength() > 0 ) {
            client->recv_buffering.add(message);
            message = new ByteBuffer;
            client->server->onReceiveMessage( client->uuid );
        }
        pthread_yield();
    }
      std::cout << "fin thread receive ! \n" ;
      return NULL;
}

void *client_thread_send ( void* data )
{
    ClientData* client = (ClientData*) data;

    SimpleTcpStartPoint *socket_server = client->server->getSocketServer();
    while ( ! client->closeMe ) {
       if ( client->send_buffering.available() ) {
            ByteBuffer* message;
            client->send_buffering.get(message);
            socket_server->send ( client->uuid, *message );
            delete message;
        }
        pthread_yield();
    }
    std::cout << "fin thread send ! \n" ;
    return NULL;
}

void SNZ_Server::OnDisconnect ( QUuid client ) {
    std::cout << "Client " << client.toString().toStdString() << " has been disconnected!!" << std::endl;
    SNZ_Server::mClients[ client ]->closeMe = true;
  /*  pthread_join(mClients [ client ]->send_thread, NULL );
    pthread_join(mClients [ client ]->recv_thread, NULL );
    if(mClients.contains(client)) {
        SNZ_Server::mClients.remove( client );
    } */
}


IMessage *SNZ_Server::getMessage(ByteBuffer &buffer) const {
    char code;
    fromBuffer<char>(buffer ,0 , code);
    return new Message<ByteBuffer>(code, &buffer);
}

void SNZ_Server::setMessageDispatcher(IMessageDispatcher *dispt) {
    mMessageDispatcher = dispt;
}


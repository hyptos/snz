#include "server.hpp"

QMap<QUuid , ClientData*> SNZ_Server::clients;

SNZ_Server::SNZ_Server() : running(false) {
  SimpleTcpStartPoint::Options options;
  options.connectionPort = 3000;
  options.cbDisconnect = OnDisconnect;
  options.maximumConnectedClients = 1;
  socketServer = new SimpleTcpStartPoint( options );
}

SNZ_Server::~SNZ_Server() {
  if(this->isRunning()) {
    this->stopServer();
  }
  delete(socketServer);
}

void SNZ_Server::start() {
  if(this->isRunning()) {
    std::cerr << "serveur is already running , abort \n";
    return;
  }
  if(!this->socketServer->start()) {
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
    std::cout << "message recu ! \n" ;
}

void SNZ_Server::stopServer() {
  if(this->isRunning()) {
    this->socketServer->stop();
  }
  this->running = false;
}

void SNZ_Server::acceptClient(QUuid client) {
    std::cout << "Client " << client.toString().toStdString() << " has connected!!" << std::endl;
    ClientData* clt_data  = new ClientData;
    clt_data->uuid        = client;
    clt_data->server      = this;
    clt_data->closeMe     = true;
    pthread_create ( &(clt_data->recv_thread), NULL, client_thread_receive, clt_data );
    pthread_create ( &(clt_data->send_thread), NULL, client_thread_send, clt_data );
    clients[ client ]     = clt_data;
}

SimpleTcpStartPoint* SNZ_Server::getSocketServer() {
    return this->socketServer;
}

void *serveur_listening_routine(void* data) {
  SNZ_Server *server = (SNZ_Server *) data;
  QUuid fake, client;
  while(server->isRunning()) {
    client = server->socketServer->listen();
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
    while ( client->closeMe ) {
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
    while ( client->closeMe ) {
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
    SNZ_Server::clients[ client ]->closeMe = false;
    pthread_join(clients [ client ]->recv_thread, NULL );
    pthread_join(clients [ client ]->send_thread, NULL );
    std::cout<< "fin joined \n";
    SNZ_Server::clients.remove( client );
}

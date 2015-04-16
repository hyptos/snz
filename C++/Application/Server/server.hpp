#ifndef SERVER_HPP
#define SERVER_HPP

#include <thread>
#include <pthread.h>
#include "TcpNetworking/simpletcpstartpoint.hpp"
#include "Message/messageHandler.hpp"
#include <vector>


typedef struct  _clientData ClientData;

class SNZ_Server {

public:

    SNZ_Server();

    ~SNZ_Server();

    void start();

    bool isRunning() const ;

    void stopServer();

    SimpleTcpStartPoint *getSocketServer();

    static void OnDisconnect ( QUuid client );

    void onReceiveMessage(QUuid client) const;

private :

    SimpleTcpStartPoint *socketServer;

    void acceptClient(QUuid client);


    friend void serveur_listening_routine(SNZ_Server *server);

protected :

    bool running;

    static QMap<QUuid, ClientData*> clients;

};

typedef struct  _clientData {
    QUuid uuid;
    //SimpleTcpStartPoint* server;
    SNZ_Server *server;
    FiFoBuffering recv_buffering, send_buffering;
    pthread_t recv_thread, send_thread;
    bool closeMe;
} ClientData;


void serveur_listening_routine(SNZ_Server *server);
void *client_thread_send (void *data);
void *client_thread_receive (void *data);

#endif // SERVER_HPP

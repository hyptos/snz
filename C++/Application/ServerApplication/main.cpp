#include "QImageLoader/qimageloader.hpp"
#include "Wavefront/wavefront.hpp"
#include <chrono>
#include <thread>
#include <pthread.h>
#include "Server/Message/messagedispatcher.hpp"
#include "Server/Message/protocolemanager.h"
#include "Server/server.hpp"
#include "Server/messagehandlerexample.hpp"

#define TRAME_TEST '}'

int main ( int argc, char** argv ) {
    SNZ_Server s;
    implMessageDispatcher dispatcher;
    MessageHandlerExample msgH;
    dispatcher.registerMessageHandler('{', (IMessageHandler*) &msgH);
    s.setMessageDispatcher(&dispatcher);
    s.start();
    while(s.isRunning()) {
        pthread_yield();
    }
    return 0;
}

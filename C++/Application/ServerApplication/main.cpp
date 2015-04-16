#include "QImageLoader/qimageloader.hpp"
#include "Wavefront/wavefront.hpp"
#include "Server/server.hpp"
#include <chrono>
#include <thread>
#include <pthread.h>

int main ( int argc, char** argv ) {
    SNZ_Server s;
    s.start();
    while(s.isRunning()) {
        pthread_yield();
    }
    return 0;
}


#include "QImageLoader/qimageloader.hpp"
#include "Wavefront/wavefront.hpp"

#include "TcpNetworking/simpletcpendpoint.hpp"

extern void __attach(void);
extern void __attachInterfaces(void);
extern void __attachGenerics(void);
extern void __attachAssets(void);
extern void __attachQImage(void);
extern void __attachWavefront(void);

int main ( int argc, char** argv ) {
    /*
    __attach();
    __attachInterfaces();
    __attachGenerics();
    __attachAssets();*/
    __attachQImage();
    __attachWavefront();

    FileDescriptor file ( argv[1]);
    SharedResourceList ress = ResourceHolder::Load(file);
    std::cout << "** Resource loaded" << std::endl;
    SharedResourcePtr ptr = ress [0];
    ByteBuffer message = ResourceHolder::ToBuffer(ptr);
    std::cout << "** Resource converted" << std::endl;

    //unsigned char* test = "machaine";
    //ByteBuffer stringtest = new ByteBuffer(test, 8);
    SimpleTcpEndPoint::Options options;
    options.serverIP = "localhost";
    options.connectionPort = 3000;
    SimpleTcpEndPoint client ( options );
    if ( client.open() == false ) exit ( -1 );
    while ( true ) {
        client.send(message); std::cout << "Sent : " << message.getLength() << " bytes" << std::endl;
        //client.receive(message); std::cout << "Recv : " << message.getLength() << " bytes" << std::endl;
    }
    client.close ();
    return 0;
}

#ifndef PROTOCOLEMANAGER
#define PROTOCOLEMANAGER

#include "message.hpp"

class IMessageDispatcher;
class IMessageHandler;

class protocoleManager {
    public :
        protocoleManager();
        ~protocoleManager();
        virtual IMessage *getMessage(ByteBuffer &buffer) const = 0;
        virtual void setMessageDispatcher(IMessageDispatcher *dispt) = 0;
};

class IMessageDispatcher {
    public :
        IMessageDispatcher();
        ~IMessageDispatcher();
        virtual void dispatchMessage(IMessage *msg) = 0;
        virtual void registerMessageHandler(int id, IMessageHandler *Me) = 0;
};

class IMessageHandler {
    virtual void onOutPutMessage(IMessage *msg) = 0;
};

#endif // PROTOCOLEMANAGER


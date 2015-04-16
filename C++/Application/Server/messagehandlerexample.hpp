#ifndef MESSAGEHANDLEREXAMPLE_H
#define MESSAGEHANDLEREXAMPLE_H

#include "Message/protocolemanager.h"
#include "Message/message.hpp"

class MessageHandlerExample : public IMessageHandler
{
public:
    MessageHandlerExample();
    ~MessageHandlerExample();
    void onOutPutMessage(IMessage *msg) {
        std::cout << "message recu dans le handler ;) \n";
    }
};

#endif // MESSAGEHANDLEREXAMPLE_H

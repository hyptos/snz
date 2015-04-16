#include "messagedispatcher.hpp"
#include "protocolemanager.h"

implMessageDispatcher::implMessageDispatcher() : IMessageDispatcher(), mProtocoleMap()
{

}

implMessageDispatcher::~implMessageDispatcher()
{

}

void implMessageDispatcher::dispatchMessage(IMessage *msg) {
    if(mProtocoleMap.find(msg->code) == mProtocoleMap.end()) {
        std::cerr << "dispatch error , message id unknow : "<< msg->code << std::endl;
        return;
    }
    std::list<IMessageHandler *> list = mProtocoleMap.at(msg->code);
    for(std::list<IMessageHandler *>::iterator it = list.begin(); it != list.end(); it++) {
        IMessageHandler *handler = (*it);
        handler->onOutPutMessage(msg);
    }
}

void implMessageDispatcher::registerMessageHandler(char id, IMessageHandler *Me) {
    if(mProtocoleMap.find(id) == mProtocoleMap.end()) {
        std::list<IMessageHandler *> list;
        mProtocoleMap[id] = list;
    }
    mProtocoleMap.at(id).push_back(Me);
}

#ifndef MESSAGEDISPATCHER_H
#define MESSAGEDISPATCHER_H

#include "protocolemanager.h"
#include <map>
#include <list>

class implMessageDispatcher : public IMessageDispatcher
{
public:

    implMessageDispatcher();

    ~implMessageDispatcher();

    void dispatchMessage(IMessage *msg);

    void registerMessageHandler(char id, IMessageHandler *Me);

protected :

    std::map<char, std::list<IMessageHandler* > > mProtocoleMap;

};

#endif // MESSAGEDISPATCHER_H

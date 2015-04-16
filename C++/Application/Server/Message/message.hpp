#ifndef MESSAGE_H
#define MESSAGE_H

#include "Utility/utility.hpp"

class IMessage
{
public:
    IMessage();
    IMessage(char var_code);
    IMessage(char var_code, void* mData);
    ~IMessage();

    template<typename T> T *getGeneriqueData() {
        return (T*) mData;
    }

    void* mData;
    char code;
};

template<typename T>
class Message : public IMessage {
public:
    Message() : IMessage() {

    }

    Message(char code ,T* data) : IMessage(code, data ) {}

    T* getData() {
        return getGeneriqueData<T>;
    };
};


#endif // MESSAGE_H

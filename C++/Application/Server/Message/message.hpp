#ifndef MESSAGE_H
#define MESSAGE_H

#include "Utility/utility.hpp"

class IMessage
{
public:
    IMessage();
    IMessage(int var_code);
    IMessage(int var_code, void* mData);
    ~IMessage();

    template<typename T> T *getGeneriqueData() {
        return (T*) mData;
    }

    void* mData;
    int code;
};

template<typename T>
class Message : public IMessage {
public:
    Message() : IMessage() {

    }

    Message(int code ,T* data) : IMessage(code, data ) {}

    T* getData() {
        return getGeneriqueData<T>;
    };
};


#endif // MESSAGE_H

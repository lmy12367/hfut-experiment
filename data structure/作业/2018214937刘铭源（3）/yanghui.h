#ifndef YANGHUI_H_INCLUDED
#define YANGHUI_H_INCLUDED
#include <iostream>
using namespace std;

const int maxlen = 100;

class _queue
{
public:
    _queue();
    bool isempty();
    bool isfull();
    bool get_front(int &x);
    bool append(int x);
    bool serve();
private:
    int _count;
    int _front,_rear;
    int  data[maxlen];
};

_queue::_queue()
{
    _count = 0;
    _front = _rear = 0;
}

bool _queue::isempty()
{
    if(_count == 0) return true;
    return false;
}

bool _queue::isfull()
{
    if(_count == maxlen - 1) return true;
    return false;
}

bool _queue::get_front(int &x)
{
    if(isempty()) return false;
    x = data[ (_front + 1) % maxlen];
    return true;
}

bool _queue::append(int x)
{
    if(isfull())  return false;
    _rear = (_rear + 1) % maxlen;
    data[_rear] = x;
    _count++;
    return true;
}

bool _queue::serve()
{
    if(isempty())  return false;
    _front = (_front + 1) % maxlen;
    _count--;
    return true;
}


#endif // YANGHUI_H_INCLUDED


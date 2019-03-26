#include <iostream>

using namespace std;

template <class T>

class GenStack
{
  public:
    GenStack();
    GenStack(int arraySize);
    ~GenStack();

    void push(T object);
    T pop();
    T peak();
    int getSize();
    bool isEmpty();
    bool isFull();

    int size;
    int top;
    T *array;
};

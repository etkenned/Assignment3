#include <iostream>
#include "GenStack.h"

using namespace std;
template <class T>
GenStack<T>::GenStack()
{
  array = new T[128];
  size = 128;
  top = -1;
}
template <class T>
GenStack<T>::GenStack(int arraySize)
{
  array = new T[arraySize];
  size = arraySize;
  top = -1;
}
template <class T>
GenStack<T>::~Genstack()
{
  delete array;
  delete GenStack();
}
template <class T>
void GenStack<T>::push(T object)
{
  if(top == size - 1)//checks if the stack is full
  {
    T *tempArray;
    tempArray = new T[size * 2]; //doubles the stack size
    for(int i = 0; i < size - 1; i++)
    {
      tempArray[i] = array[i];
    }
    array = tempArray;
    size = size * 2;
  }
  array[top++] = object; //adds object to the stack
}
template <class T>
T GenStack<T>::pop()
{
  if(isEmpty())//checks if the array is empty
  {
    return '0'; // exception *********************************************************
  }
  else
  {
    T temp = array(top--);
    return temp;
  }
}
template <class T>
T GenStack<T>::peak()
{
  return array(top);
}
template <class T>
int GenStack<T>::getSize()
{
  return size;
}
template <class T>
bool GenStack<T>::isEmpty()
{
  return (top == -1);
}
template <class T>
bool GenStack<T>::isFull()
{
  return (top == size - 1);
}

//Martin Wilson
//stack.cpp
//Implementation of the stack class

using namespace std;

#include "stack.h"

Stack::Stack(int size)
{
  if(size <= 5)
    size = 20;
  list = new int[size];
  top = -1;
  max = size;

  for(int i = 0; i < max; i++)
    list[i] = 0;

}

Stack::Stack(const Stack& s)
{
  top = s.top;
  max = s.max;
  list = new int[max];

  for(int i = 0; i < max; i++)
    list[i] = s.list[i];

}

Stack& Stack::operator=(const Stack& rhs)
{
  if(this != &rhs){
    delete [] list;
    max = rhs.max;
    top = rhs.top;
    list = new int[max];

    for(int i = 0; i < max; i++)
      list[i] = rhs.list[i];
  }

  return *this;
}

Stack::~Stack()
{
  delete [] list;
}

void Stack::push(int data)
{
  if(full())
    reSize();

  if(data%2 != 0){
    top++;
    list[top] = data;
  }
}

int Stack::pop()
{
  if(isEmpty())
    throw EmptyStack();

  int lastIndex = top;
  top--;
  return list[lastIndex];
}

bool Stack::isEmpty() const
{
  return top == -1;
}

bool Stack::full() const
{
  return top == max - 1;
}
void Stack::reSize()
{
  int* temp;
  int newSize = 1.5*max;
  temp = new int[newSize];

  for(int i = 0; i <= max; i++)
    temp[i] = list[i];

  max = newSize;

  delete [] list;
  list = temp;
}

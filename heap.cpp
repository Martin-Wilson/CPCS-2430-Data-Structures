//Martin Wilson
//heap.cpp
//Implementation of heap class

using namespace std;

#include "heap.h"

Heap::Heap(int value)
{
  if(value <= 8)
    size = 30;
  heap = new int[size];
  curSize = 0;
}

Heap::Heap(const Heap& h)
{
  size = h.size;
  curSize = h.curSize;
  heap = new int[size];

  for(int i = 0; i < size; i++)
    heap[i] = h.heap[i];
}

Heap& Heap::operator=(const Heap& rhs)
{
  if(this != &rhs){
    delete [] heap;
    size = rhs.size;
    curSize = rhs.curSize;
    heap = new int[size];
  

    for(int i = 0; i < size; i++)
      heap[i] = rhs.heap[i];
  }

  return *this;
}

Heap::~Heap()
{
  delete [] heap;
}

void Heap::insert(int data)
{
  if(full())
    reSize();

  curSize += 1;
  int hole = curSize;
  int temp;

  heap[hole] = data;

  while(hole > 1 && heap[hole] < heap[hole/2]){
    temp = heap[hole/2];
    heap[hole/2] = heap[hole];
    heap[hole] = temp;
    hole = hole/2;
  }
}

int Heap::remove()
{
  int temp = heap[1];
  heap[1] = heap[curSize];
  curSize--;
  percDown(1);
  return temp;
}

void Heap::flush(int target)
{ 
  for(int i = 1; i < curSize + 1; i++){
    if(heap[i] == target){
      heap[i] = heap[curSize];
      curSize--;
      percDown(1);
      i = 1;
    }
  }
}

bool Heap::isEmpty() const
{
  return curSize == 0;
}

bool Heap::full() const
{
  return curSize == size;
}

void Heap::reSize()
{
  int* temp;
  int newSize = 1.5*size;
  temp = new int[newSize];

  for(int i = 0; i <= size; i++)
    temp[i] = heap[i];

  size = newSize;

  delete heap;
  heap = temp;
}

void Heap::percDown(int start)
{
  int temp = heap[start];

  while((start * 2 <= curSize && temp > heap[start*2]) ||
        (start*2+1 <= curSize && temp > heap[start*2+1])){
    if(start*2+1 <= curSize && heap[start*2+1] < heap[start*2]){
      heap[start] = heap[start*2+1];
      start = start*2+1;
    } else {
      heap[start] = heap[start*2];
      start = start*2;
    }
  }
  heap[start] = temp;
}

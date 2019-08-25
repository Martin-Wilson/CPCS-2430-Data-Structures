//Martin Wilson
//heap.h
//Documentation and header file for a min heap class

#ifndef HEAP_H
#define HEAP_H

class Heap
{
 public:

  Heap(int size = 35);
  //Explicit constructor, call in order to create a heap object
   
  Heap(const Heap& h);
  //Copy constructor
   
  Heap& operator=(const Heap& rhs);
  //Overloaded assignment operator
   
  ~Heap();
  //Destructor, deallocates all the memory used by the heap

  void insert(int data);
  //IN: Takes in an integer to add into the heap
  //MODIFY: Adds a value into the heap
  //OUT: Does not return anything

  int remove();
  //IN: Does not take anything in
  //MODIFY: Removes one the minimum value from the heap
  //OUT: Returns the minimum value from the heap

  void flush(int target);
  //IN: Takes in an integer
  //MODIFY: Removes all instances of the take in integer within the heap
  //OUT: Does not return anything

  bool isEmpty() const;
  //IN: Does not take anything
  //MODIFY: Does not modify anything
  //OUT: Returns true if the heap is empty and false if it is not

 private:

  int* heap;
  int size;
  int curSize;
  
  bool full() const;
  //IN: Does not take anything in
  //MODIFY: Does not modify the heap
  //OUT: Return true if the heap is full and false if it is not full

  void reSize();
  //IN: Does not take anything in
  //MODIFY: Increases the size of the heap
  //OUT: Does not return anything

  void percDown(int start);
  //IN: Takes in an integer to where the values should percolate down from
  //MODIFY: Moves values in the heap to maintain order
  //OUT: Does not return anything

};

#endif //HEAP_H

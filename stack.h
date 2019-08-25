//Martin Wilson
//stack.h
//Stack class that only takes in odd integers

#ifndef STACK_H
#define STACK_H

class Stack
{
 public:

  class EmptyStack{};
  //empty class exception thrown if there is an attempt to pop from empty stack

  explicit Stack(int size = 10);
  //explicit constructor, call in order to create a stack

  Stack(const Stack& s);
  //copy constructor of stack

  Stack& operator=(const Stack& rhs);
  //overloaded assignment operator

  ~Stack();
  //Deconstructor, deallocates all the memeory used by the stack

  void push(int data);
  //IN: Takes in an odd integer value that will be added
  //to the top of the stack. It will not accept even integers and will not
  //give an error message if attempted
  //MODIFY: Will add a value to the stack
  //OUT: Does not return anything

  int pop();
  //IN: Does not take anything in
  //MODIFY: Removes the top value from stack
  //OUT: Returns the top value from the stack

  bool isEmpty() const;
  //IN: Does not take anything in
  //MODIFY: Does not modify the stack
  //OUT: Returns true if the stack is empty and false if it is not

 private:
  int* list;
  int max;
  int top;

  bool full() const;
  //IN: Does not take anything in
  //MODIFY: Does not modify the stack
  //OUT: returns true if the stack is full and false if it not

  void reSize();
  //IN: Does not take anything in
  //MODIFY: Resizes the stack to 1.5 times the original size
  //OUT: does not return anything

};

#endif //STACK_H

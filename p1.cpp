//Martin Wilson
//p1.cpp
//Driver class to test stack class

#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
  
  cout << endl << endl << "Testing stack class." << endl
       << "Creating two stacks(s1 and s3) of size 10";

  Stack s1(10);
  Stack s3(10);

  cout << endl << endl << "Pushing 10 odd values onto the stack(s1)." << endl
       << "Pushing ";

  for(int i = 1; i < 21; i += 2){
    cout << i << "  ";
    s1.push(i);
  }

  cout << endl << "on to the stack." << endl << "Press enter to continue";
  cin.get();
  cout << endl
       << "Testing copy constructor by creating a copy stack(s2) of the "
       << "first(s1)";

  Stack s2(s1);

  cout << endl << "Now popping values from both stacks(s1 and s2)" << endl;

  while(!s1.isEmpty()){
    cout << s1.pop() << "  ";
  }

  cout << endl;

  while(!s2.isEmpty()){
    cout << s2.pop() << "  ";
  }

  cout << endl << endl << "Now pushing 15 values onto s1 which is size 10"
       << endl << "Press enter to continue";
  cin.get();
  cout << endl << "Testing resize and full methods" << endl;

  for(int i = 1; i < 30; i += 2){
    cout << i << "  ";
    s1.push(i);
  }

  cout << endl << endl << endl << "Testing overloaded assignment operator"
       << " by copying s1 into s3, a new stack.";

  s3 = s1;

  cout << endl << "Now popping values from both stacks(s1 and s3)" << endl;

  while(!s1.isEmpty()){
    cout << s1.pop() << "  ";
  }

  cout << endl;

  while(!s3.isEmpty()){
    cout << s3.pop() << "  "; 
  }

  cout << endl << "Press enter to continue";
  cin.get();

  cout << endl
       << "Attempting to push 20 even and odd numbers on the stack(s1)" << endl;

  for(int i = 1; i < 20; i++){
    cout << i << "  ";
    s1.push(i);
  }

  cout << endl << "Now popping values from the stack(s1)" << endl;

  while(!s1.isEmpty()){
    cout << s1.pop() << "  ";
  }

  cout << endl << endl << "Press enter to continue";
  cin.get();
  cout << endl << "Attempting to pop from an empty stack(s3)";

  try{
    cout << endl << s3.pop();
  }
  catch (Stack::EmptyStack){
    cout << endl << "ERROR: Cannot pop from empty stack.";
  }

  return 0;
}

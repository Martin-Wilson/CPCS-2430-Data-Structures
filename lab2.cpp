//Martin Wilson
//lab2.cpp
//A program that recursivly finds and displays the last occurrence of a
//negative number in a linked list (value furthers from the head)

#include <iostream>
#include <iomanip>

using namespace std;

struct Node
{
  int data;
  Node* next;
};

void findNeg(Node* head, bool& done);

void add(Node*& head, int value);

const int MIN = -99;
const int MAX = 99;
const int WIDE = 3;

int main()
{
  Node* head = nullptr;
  Node* ptr;
  
  int num;
  int counter = 0;

  bool finished = false;
  
  unsigned seed = time(0);
  srand(seed);

  cout << endl << "How many nodes would you like on the list? ";
  cin >> num;

  for(int i  = 0; i < num; i++)
    add(head,(rand()%(MAX - MIN + 1) + MIN));

  ptr = head;

  cout << endl << endl << "Printing out the entire list." << endl;
  
  while(ptr != nullptr){
    cout << setw(WIDE) << ptr -> data << ", ";
    ptr = ptr -> next;
    counter++;

    if(counter >= 3){
      cout << endl;
      counter = 0;
    }
  }


  cout << endl << endl << "The last negative number is ";

  findNeg(head, finished);
  
  cout << endl << endl;
  
  while(head != nullptr){
    ptr = head;
    head = head -> next;
    delete ptr;
  }
  
  return 0;
}

void findNeg(Node* head, bool& done)
{
  Node* ptr = head;
  
  if(ptr != nullptr){
    findNeg(ptr -> next, done);

    if(ptr -> data < 0 && !done){
      cout << ptr -> data;
      done = true;
    }
    
  }
}


void add(Node*& head, int value)
{
  Node* temp = new Node;
  temp -> data = value;

  Node* ptr;
  
  
  if(head == nullptr){
    head = temp;
    
  } else {
    ptr = head;

    while(ptr -> next != nullptr)
      ptr = ptr -> next;

    ptr -> next = temp;
  }
}

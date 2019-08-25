//Martin Wilson
//p2.cpp
//A program that creates an unorders linked list and prints it into a file.
//It removes the first, last and a middle value from the list and
//prints the updated list to a different file.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

struct Node
{
  int data;
  Node* next;
};

void printList(Node* head, ostream& outfile);
//IN: Takes in the pointer to the head of the list
//MODIFY: Does not modify the list in anyway
//OUT: Prints the list to a file

void insertElement(Node*& head, int value);
//IN: Takes in a pass by reference pointer to the head of the list and a value
//to be added to the list
//MODIFY: Adds an element into the list
//OUT: Does not return or output anything

void removeElement(Node*& head, int value);
//IN: Takes in a pass by reference pointer to the head of the list and a value
//to be removed from the list
//MODIFY: Removes an element from the list
//OUT: Does not return or output anything

void delList(Node*& head);
//IN: Takes in a pass by reference pointer to the head of the list
//MODIFY: Deletes every node in the list
//OUT: Does not return or output anything

const int MIN = -99;
const int MAX = 99;
const int SIZE = 55;
const int MIDDLE = SIZE/2;
const int WIDTH = 3;

int main()
{
  unsigned seed = time(0);
  srand(seed);

  int counter = 0;
  
  Node* head = nullptr;
  Node* temp;

  ofstream outfile;
  outfile.open("OutputA.txt");
  
  cout << endl << "Putting " << SIZE << " random"
       << " values from " << MIN << " to " << MAX
       << " into an order linked list.";
  
  for(int i = 0; i < SIZE; i++){
    insertElement(head, (rand()% (MAX - MIN + 1)+ MIN));
  }
  
  printList(head, outfile);
  outfile.close();

  cout << endl << "Removing the smallest, largest, and a random value from the"
       << " middle of the list." << endl << endl;

  temp = head;
  
  while(counter != MIDDLE){
    temp = temp-> next;
    counter++;
  }

  removeElement(head, temp -> data);
  
  while(temp -> next != nullptr)
    temp = temp -> next;

  removeElement(head, temp -> data);

  removeElement(head, head -> data);
  
  outfile.open("OutputB.txt");
  printList(head, outfile);
  outfile.close();
  
  delList(head);

  return 0;
}

void printList(Node* head, ostream& outfile)
{
  Node* temp = head;
  int counter = 0;
  
  while(temp != nullptr){
    outfile << setw(WIDTH) << temp -> data << ", "; 
    temp = temp -> next;
    counter++;
    if(counter > 5){
      counter = 0;
      outfile << endl;
    }      
  }
}

void insertElement(Node*& head, int value)
{
  Node* temp = new Node;
  Node* ptr;
  
  temp -> data = value;

  if(head == nullptr || head -> data > temp -> data){
    temp -> next = head;
    head = temp;
  } else {
    ptr = head;

    while(ptr -> next != nullptr && ptr -> next -> data < temp -> data)
      ptr = ptr -> next;
  
    temp -> next = ptr -> next;
    ptr -> next = temp;
  }
}

void removeElement(Node*& head, int value)
{
  Node* delptr = head;
  Node* previous;
  
  if(value == head -> data){
    head = head -> next;
    delete delptr;
  } else {
    while(value != delptr -> data && delptr != nullptr){
      previous = delptr;
      delptr = delptr -> next;
    }

    if(delptr -> data == value){
      previous -> next = delptr -> next;
      delete delptr;
    }
  }
}


void delList(Node*& head)
{
  Node* delptr;

  while(head != nullptr){
    delptr = head;
    head = head -> next;
    delete delptr;
  }
}

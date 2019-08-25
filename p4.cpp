//Martin Wilson
//p4.cpp
//Driver for testing heap class will create a BST with 35 random numbers to
//test all the methods

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "heap.h"
#include <iomanip>

using namespace std;

const int MAX = 99;
const int MIN = -99;
const int ASIZE = 35;
const int NEWLINE = 10;
const int VAL = 12;
const int WIDTH = 3;

int main()
{
  cout << endl << "Creating a heap named h1 of size 20";

  Heap h1(20);
  int arr[ASIZE];
  int counter = 0;

  unsigned seed = time(0);
  srand(seed);

  for(int i = 0; i < ASIZE; i++){
    arr[i] =(rand()% (MAX - MIN +1)+ MIN);
  }

  cout << endl << "We will be testing the heap with these values."
       << endl << endl;

  for(int i = 1;i <= ASIZE; i++){
    cout << setw(WIDTH) << arr[i-1] << ' ';
    if(i % NEWLINE == 0)
      cout << endl;
  }

  cout << endl << endl << "Testing the insert method as well as the resize and"
       << " full methods." << endl << "We will be inserting " << ASIZE
       << " numbers of values into h1 which is size 20.";

  for(int i = 0; i < ASIZE; i++)
    h1.insert(arr[i]);

  cout << endl << endl << "Testing the copy constructor by creating a new"
       << " heap named h2.";

  Heap h2(h1);

  cout << endl << endl << "Testing the remove method by removing all values"
       << " from h1 and h2." << endl << endl;

  while(!h1.isEmpty()){
    cout << setw(WIDTH) << h1.remove() << ' ';
    counter++;
    if(counter%NEWLINE == 0){
      cout << endl;
      counter = 0;
    }
  }
	
  counter = 0;

  cout << endl << endl;

  while(!h2.isEmpty()){
    cout << setw(WIDTH) << h2.remove() << ' ';
    counter++;
    if(counter%NEWLINE == 0){
      cout << endl;
      counter = 0;
    }
  }

  counter = 0;

  cout << endl << endl << "Testing OAO by creating a new heap named h3 and "
       << "copying h1 into h3" << endl 
       << "H1 will be filled again with the given values.";

  for(int i = 0; i < ASIZE; i++)
    h1.insert(arr[i]);

  Heap h3;
  h3 = h1;

  cout << endl << endl << "Removing all values from h3 and h1" << endl << endl;

  while(!h1.isEmpty()){
    cout << setw(WIDTH) << h1.remove() << ' ';
    counter++;
    if(counter%NEWLINE == 0){
      cout << endl;
      counter = 0;
    }
  }

  counter = 0;

  cout << endl << endl;

  while(!h3.isEmpty()){
    cout << setw(WIDTH) << h3.remove() << ' ';
    counter++;
    if(counter%NEWLINE == 0){
      cout << endl;
      counter = 0;
    }
  }

  counter = 0;
  
  cout << endl << endl << "H1 will be refilled with given values";
       
  cout << endl << "Testing the flush method by flushing "
       << arr[VAL]
       << " from h1." << endl << endl;

  for(int i = 0; i < ASIZE; i++)
    h1.insert(arr[i]);

  for(int i = 0; i < 4; i++)
    h1.insert(arr[VAL]);

  h1.flush(arr[VAL]);

  while(!h1.isEmpty()){
    cout << setw(WIDTH) << h1.remove() << ' ';
    counter++;
    if(counter%NEWLINE == 0){
      cout << endl;
      counter = 0;
    }
  }

  cout << endl << endl;
  
  return 0;
}

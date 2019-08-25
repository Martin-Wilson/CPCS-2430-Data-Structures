//Martin Wilson
//p3.cpp
//A program that creates a BST with 20 "random" numbers that tests all the
//methods of the tree.cpp file

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "tree.h"

using namespace std;

const int ASIZE = 30;
const int MAX = 70;
const int MIN = -70;
const int NEWLINE = 10;
const int TARGET = 7;
const int NOTTARGET = 75;

int main()
{

  cout << endl << "Creating a BST named tree1";
  
  Tree tree1;
  int arr[ASIZE];

  bool success;

  unsigned seed = time(0);
  srand(seed);
  
  for(int i = 0; i < ASIZE; i++){
    arr[i] = (rand()% (MAX - MIN +1) + MIN);
  }

  cout << endl << "We will be testing the BST with these values"
       << endl << endl;

  for(int i = 1; i <= ASIZE; i++){
    cout << arr[i-1] << ' ';
    if(i%NEWLINE  == 0)
      cout << endl;
  }

  cout << endl << endl << "Testing the insert method." << endl;

  for(int i = 0; i < ASIZE; i++){
    tree1.insert(arr[i]);
  }

  cout << endl << "Testing the Pre-Order Traversal print of the BST tree1"
       << endl << endl;
  tree1.preOrderTraversal();

  cout << endl << endl << endl
       << "Testing the copy constructor by copying tree1 into a new"
       << "tree named tree2";

  Tree tree2(tree1);

  cout << endl << "Printing the values of both trees by In-Order Traversal"
       << endl << endl;

  tree1.inOrderTraversal();

  cout << endl << endl;

  tree2.inOrderTraversal();

  cout << endl << endl << endl
       << "Testing the overloaed assignment operator by creating a"
       << endl << "new BST named tree3 and copying the values from tree2"
       << endl;

  Tree tree3;
  tree3 = tree2;

  cout << endl << "Printing the values of tree 2 and tree 3 by Pre-Order "
       << "Traversal" << endl;

  tree2.preOrderTraversal();

  cout << endl << endl;

  tree3.preOrderTraversal();

  cout << endl << endl << endl
       << "Testing the search method of the BST by searching for"
       << "the value " << arr[TARGET] << " in tree3"
       << endl << "as well as a value not in tree3(" << NOTTARGET << ')'
       << endl;
  
  success = tree3.findKey(arr[TARGET]);

  if(success)
    cout << endl << "Value " << arr[TARGET] << " found in tree3";
  else
    cout << endl << "Value " << arr[TARGET] << " was not found in tree3";

  success = tree3.findKey(NOTTARGET);

  if(success)
    cout << endl << "Value " << NOTTARGET << " found in tree3";
  else
    cout << endl << "Value " << NOTTARGET << " not found in tree3";

  cout << endl << endl << endl
       << "Testing the findMinKey method in tree2, will print"
       << "the min value from tree2";

  cout << endl << tree2.findMinKey();

  cout << endl << "Testing the findHeight method in tree1, will print the "
       << "height of tree1";

  cout << endl << tree1.findHeight() << endl << endl;

  return 0;
}

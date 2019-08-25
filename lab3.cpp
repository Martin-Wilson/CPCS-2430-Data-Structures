//Martin Wilson
//lab3.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Tnode
{
  int key;
  Tnode* left;
  Tnode* right;
};

bool insert(Tnode*& root, int data);
//Returns true if it is added to the list and false if it doesn't

void inorderPrint(Tnode* root);

void preorderPrint(Tnode* root);

void postorderPrint(Tnode* root);

void delTree(Tnode*& root);

int main()
{
  unsigned seed = time(0);
  srand(seed);

  Tnode* root = nullptr;

  int counter = 0;
  bool success;
  
  while(counter < 10){
    success = insert(root, (rand()% (30 - 0 + 1) + 0));

    if(success){
      counter++;
    } else {
      cout << endl << "Unable to add value to tree as it is a duplicate";
    }
  }

  
  cout << endl << endl;
  inorderPrint(root);

  cout << endl << endl;
  preorderPrint(root);

  cout << endl << endl;
  postorderPrint(root);

  delTree(root);
  
  return 0;
}

bool insert(Tnode*& root, int data)
{
  if(root == nullptr){
    root = new Tnode;
    root -> key = data;
    root -> left = nullptr;
    root -> right = nullptr;
    return true;
  } else if(root -> key == data){
    return false;
  } else if(root -> key > data){
    return insert(root -> left, data);
  } else {
    return insert(root -> right, data);
  }

}

void inorderPrint(Tnode* root)
{
  if(root != nullptr){
    inorderPrint(root -> left);
    cout << root -> key << ", ";
    inorderPrint(root -> right);
  }
}

void preorderPrint(Tnode* root)
{
  if(root != nullptr){
    cout << root -> key << ", ";
    preorderPrint(root -> left);
    preorderPrint(root -> right);
  }
}

void postorderPrint(Tnode* root)
{
  if(root != nullptr){
    postorderPrint(root -> left);
    postorderPrint(root -> right);
    cout << root -> key << ", ";
  }
}

void delTree(Tnode*& root)
{
  if(root != nullptr){
    delTree(root -> left);
    delTree(root -> right);
    delete root;
    root = nullptr;
  }
}

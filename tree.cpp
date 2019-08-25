//Martin Wilson
//tree.cpp
//Implementation of the tree class

#include <stack>
#include <iostream>
#include "tree.h"

using namespace std;

Tree::Tree()
{
  root = nullptr;
}

Tree::Tree(const Tree& bST)
{
  if(bST.root == nullptr)
    root = nullptr;
  else
    root = copyTree(bST.root);
}

Tree& Tree::operator=(const Tree& rhs)
{
  if(this != &rhs){
    delTree(root);
    root = copyTree(rhs.root);
  }
  return *this;
}

Tree::~Tree()
{
  delTree(root);
}

void Tree::insert(int data)
{
  insert(root, data);
}

bool Tree::findKey(int target) const
{
  return findKey(root, target);
}

int Tree::findMinKey()
{
  return findMinKey(root);
}

int Tree::findHeight() const
{
  return findHeight(root);
}

void Tree::preOrderTraversal() const
{
  preOrderTraversal(root, counter);
}

void Tree::inOrderTraversal() const
{
  inOrderTraversal(root, counter);
}

void Tree::delTree(Tnode*& root)
{
  if(root != nullptr){
    delTree(root -> left);
    delTree(root -> right);
    delete root;
    root = nullptr;
  }
}

bool Tree::insert(Tnode*& root, int data)
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

bool Tree::findKey(Tnode* root, int target) const
{
  if(root == nullptr)
    return false;
  else if(root -> key == target)
    return true;
  else if(root -> key > target)
    return findKey(root -> left, target);
  else
    return findKey(root -> right, target);
}

int Tree::findMinKey(Tnode*& root)
{
  if(root -> left == nullptr)
    return root -> key;
  else
    return findMinKey(root -> left);
}

int Tree::findHeight(Tnode* root) const
{
  if(root == nullptr)
    return 0;
  else {
    int lHeight = findHeight(root -> left);
    int rHeight = findHeight(root -> right);
    if(lHeight > rHeight)
      return 1 + lHeight;
    else
      return 1 + rHeight;
  }
}

void Tree::preOrderTraversal(Tnode* root, int counter) const
{

  if(root != nullptr){
    cout << root -> key << ' ';
    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);
  }
}

void Tree::inOrderTraversal(Tnode* root) const
{
  stack<Tnode*> s1;

  Tnode* temp = root;

  while(temp != nullptr || !s1.empty()){
    while(temp != nullptr){
      s1.push(temp);
      temp = temp ->left;
    }
  
    temp = s1.top();
    s1.pop();

    cout << temp -> key << ' ';

    temp = temp -> right;
  }

}

Tree::Tnode* Tree::copyTree(Tnode* root) const
{
  if(root == nullptr)
    return nullptr;
  else{
    Tnode* temp = new Tnode;
    temp -> key = root -> key;
    temp -> left = copyTree(root -> left);
    temp -> right = copyTree(root -> right);
    return temp;
  }
}

//Martin Wilson
//tree.h
//Documentation and header file for a partial BST that stores integers as
//the data/key

#ifndef TREE_H
#define TREE_H

class Tree
{
 private:

  struct Tnode{
    int key;
    Tnode* left;
    Tnode* right;
  };

  Tnode* root;

  void delTree(Tnode*& root);
  //IN: Takes in a pass by reference pointer to the root of the BST
  //OUT: Does not output anything
  //MODIFY: Deletes all the values in the BST

  bool insert(Tnode*& root, int data);
  //IN: Takes in an integer to insert into the BST and a pointer to the root
  //of the BST
  //OUT: Returns false if the key/data is already present in the BST and true
  //if the key is not in the BST
  //MODIFY:Adds the key/data into the BST if there is no other value equal to
  //the key/data
  //NOTE: Will not add duplicates to the BST and will now throw an error or
  //exception

  bool findKey(Tnode* root, int target) const;
  //IN: Takes in a target integer to search for in the BST and a pointer to the
  //root of the BST
  //OUT: Returns a true if the target value in the BST and false if the
  //target value is not in the BST
  //MODIFY: Does not modify the BST

  int findMinKey(Tnode*& root);
  //IN: Takes in a pass by reference pointer to the root of the BST
  //OUT: returns the smallest key value in the BST
  //MODIFY: Removes the smallest value from the tree
  
  int findHeight(Tnode* root) const;
  //IN: Takes in a pointer to the root of the BST
  //OUT: returns the height of the BST
  //MODIFY Does not modify the BST

  void preOrderTraversal(Tnode* root, int& counter) const;
  //IN: Takes in a pointer to the root of the BST and an pass by refernce
  //int counter for printing new lines
  //OUT: Prints the values of the BST by Pre-Order Traversal
  //MODIFY: Does not modify the BST

  void inOrderTraversal(Tnode* root, int& counter) const;
  //IN: Takes in a pointer to the root of the BST and an pass by reference
  //int counter for printing new lines
  //OUT: Prints the values of the BST by In-Order Traversal
  //MODIFY: Does not modify the BST

  Tnode* copyTree(Tnode* root) const;
  //IN: Takes in a pointer to the root of the BST
  //OUT: Returns a pointer to the root of the freshly copied BST
  //MODIFY: Does not modify the BST

 public:

  Tree();
  //Constructor, call in order to create a BST

  Tree(const Tree& bST);
  //Copy constructor of BST

  Tree& operator =(const Tree& rhs);
  //Overloaded assignment operator

  ~Tree();
  //Deconstructor, deallocates all memeory used by the BST

  void insert(int data);
  //IN: Takes in an integer to insert into the BST
  //OUT: Does not return anything
  //MODIFY:Adds the key/data into the BST if there is no other value equal to
  //the key/data 
  //NOTE: Calls the private insert method as it is recursive
  //NOTE: Will not add duplicates to the BST and will not throw an error or
  //exception

  bool findKey(int target) const;
  //IN: Takes in a target integer to search for in the BST
  //OUT: Returns a true if the target value in the BST and false if the
  //target value is not in the BST
  //MODIFY: Does not modify the BST
  //NOTE: Calls the private findKey method as it is recursive

  int findMinKey();
  //IN: Does not take anything in
  //OUT: Returns the smallest key value in the BST
  //MODIFY: Does not modify the BST
  //NOTE: Calls the private findMinKey method as it is recursive

  int findHeight() const;
  //IN: Does not take in anything
  //OUT: returns the height of the BST
  //MODIFY Does not modify the BST
  //NOTE: Calls the private findHeight method as it is recursive

  void preOrderTraversal() const;
  //IN: Does not take anything in
  //OUT: Prints the values of the BST by Pre-Order Traversal
  //MODIFY: Does not modify the BST
  //NOTE: Calls the private preOrderTraversal method as it is recursive

  void inOrderTraversal() const;
  //IN: Takes in a pointer to the root of the BST
  //OUT: Prints the values of the BST by In-Order Traversal
  //MODIFY: Does not modify the BST
  //NOTE: Calls the private inOrderTraversal method
  
 
};

#endif //TREE_H



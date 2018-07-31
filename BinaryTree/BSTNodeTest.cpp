#include<iostream>
#include "BSTNode.h"

using namespace std;

int main() {
  // rootPtr to access all linked nodes
  BSTNode<int>* rootPtr;
  // declare three nodes
  // one child with no param constructor
  // one child with item param constructor
  // one parent with three param constructor
  BSTNode<int>* lChild = new BSTNode<int>();
  lChild->setItem(16);
  cout << "Left Child Node has " << lChild->getItem() << endl;

  BSTNode<int>* rChild = new BSTNode<int>(25);
  cout << "Right Child Node has " << rChild->getItem() << endl;

  BSTNode<int>* parent = new BSTNode<int>(19, lChild, rChild);
  rootPtr = parent;
  cout << "Parent Node has " << rootPtr->getItem() << endl;

  // check isLeaf()
  cout << "Is left child leaf? " << lChild->isLeaf() << endl;
  cout << "Is right child leaf? " << rChild->isLeaf() << endl;
  cout << "Is parent leaf? " << rootPtr->isLeaf() << endl;

  // getLeft and getRight
  cout << "Nodes in tree view:" << endl;
  cout << "   " << rootPtr->getItem() << endl;
  cout << rootPtr->getLeftChild()->getItem() << "    " << rootPtr->getRightChild()->getItem() << endl;

  // declare new and set it to the left of lChild
  BSTNode<int>* lGrandChild = new BSTNode<int>(12);
  lChild->setLeftChild(lGrandChild);

  cout << "Is left child leaf? " << lChild->isLeaf() << endl;
  cout << "Is left grand child leaf? " << lGrandChild->isLeaf() << endl;
  cout << "Left Grand Child Node has " << lChild->getLeftChild()->getItem() << endl;


  return 0;
}

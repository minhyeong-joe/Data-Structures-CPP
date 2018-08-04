#include<iostream>
#include<string>
#include "BinarySearchTree.h"

using namespace std;

int main() {
  BinarySearchTree<string>* BST = new BinarySearchTree<string>("J");
  cout << "Is empty? " << BST->isEmpty() << endl;

  cout << BST->getRootData() << endl;

  BST->add("R");
  BST->add("A");
  BST->add("B");
  BST->add("T");
  BST->add("S");
  BST->add("V");
  BST->add("P");
  BST->add("L");

  BST->printPreorder();

  cout << "Height of the tree is " << BST->getHeight() << endl;
  cout << "Binary Search for 'V': " << BST->contains("V") << endl;

  BST->printInorder();

  // BST->remove("J");

  BST->printInorder();

  cout << "Is empty? " << BST->isEmpty() << endl;
  cout << "Clear Tree..." << endl;
  BST->clear();
  cout << "Is empty? " << BST->isEmpty() << endl;
  cout << "Height of the tree is " << BST->getHeight() << endl;
  cout << BST->getNodeCount() << endl;

  BST->printInorder();

  cout << endl << "*** Sorting array of integers using BST ***" << endl;
  int numberArray[] =  {6,3,9,32,15,39,23,4,8,17,4,7,12,21};
  BinarySearchTree<int>* treeSort = new BinarySearchTree<int>;
  cout << "Unsorted: ";
  for(int n : numberArray) {
    cout << n << " ";
    treeSort->add(n);
  }
  cout << endl << "Sorted:   ";
  treeSort->printInorder();

  return 0;
}

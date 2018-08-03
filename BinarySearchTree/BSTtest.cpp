#include<iostream>
#include<string>
#include "BinarySearchTree.h"

using namespace std;

int main() {
  BinarySearchTree<string>* BST = new BinarySearchTree<string>("James");

  cout << BST->getRootData() << endl;

  BST->add("John");
  BST->add("Abel");
  BST->add("Kim");
  BST->add("Charlie");
  BST->add("Tim");
  BST->add("Paul");

  BST->printInorder();

  return 0;
}

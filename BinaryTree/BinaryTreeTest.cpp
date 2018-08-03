#include<iostream>
#include<string>
#include "LinkedBinaryTree.h"
using namespace std;

int main() {
  string root = "I AM ROOT";
  BSTNode<string>* left = new BSTNode<string>("Left Child");
  BSTNode<string>* right = new BSTNode<string>("Right Child");
  LinkedBinaryTree<string>* binTree = new LinkedBinaryTree<string>(root, left, right);
  LinkedBinaryTree<string>* copiedTree = new LinkedBinaryTree<string>(binTree);
  cout << binTree->getHeight();
  return 0;
}

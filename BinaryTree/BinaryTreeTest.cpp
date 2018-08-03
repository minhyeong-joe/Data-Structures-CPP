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
  cout << copiedTree->getHeight() << endl;
  cout << copiedTree->getNodeCount() << endl;
  cout << copiedTree->getRoot() << endl;
  binTree->setRoot("New Root");
  cout << binTree->getRoot() << endl;
  binTree->preOrder();
  binTree->add("new child1");
  binTree->add("new child2");
  binTree->add("new child3");
  binTree->add("new child4");
  binTree->add("new child5");
  binTree->preOrder();
  cout << binTree->getHeight() << endl;
  cout << binTree->getNodeCount() << endl;
  cout << binTree->contains("new child4") << endl;
  binTree->preOrder();
  binTree->inOrder();
  binTree->postOrder();
  return 0;
}

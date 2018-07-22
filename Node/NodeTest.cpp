#include<iostream>
#include<string>
#include "Node.h"

using namespace std;

int main() {
  // instantiate three nodes
  Node<string>* node1 = new Node<string>("First");
  Node<string>* node2 = new Node<string>("Second");
  Node<string>* node3 = new Node<string>("Third");

  // Link the nodes in chain.
  node1->setNext(node2);
  node2->setNext(node3);

  // Show nodes in order
  Node<string>* headPtr = node1;
  while(headPtr != NULL) {
    cout << headPtr->getItem() << endl;
    headPtr = headPtr->getNext();
  }
  return 0;
}

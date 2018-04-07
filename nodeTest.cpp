#include<iostream>
#include<string>
#include "Node.h"

using namespace std;

int main() {
  Node<string>* headPtr;
  Node<string>* n1 = new Node<string>("a");
  Node<string>* n2 = new Node<string>("b");
  Node<string>* n3 = new Node<string>("c");
  n1->setNext(n2);
  n2->setNext(n3);
  headPtr = n1;
  for(int i=0; i<3; i++) {
    cout << headPtr->getItem() << endl;
    headPtr = headPtr->getNext();
  }
  return 0;
}

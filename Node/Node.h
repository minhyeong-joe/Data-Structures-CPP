#ifndef _NODE_H
#define _NODE_H

template <class ItemType>
class Node {
private:
  ItemType item;
  Node<ItemType>* next;
public:
  Node();
  Node(const ItemType& newItem);
  Node(const ItemType& newItem, Node<ItemType>* nextPtr);

  void setItem(const ItemType& newItem);
  void setNext(Node<ItemType>* nextPtr);
  ItemType getItem();
  Node<ItemType>* getNext();
};

#include "Node.cpp"
#endif

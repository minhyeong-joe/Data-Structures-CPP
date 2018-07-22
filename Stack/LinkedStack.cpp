#include "LinkedStack.h"

template <class ItemType>
LinkedStack<ItemType>::LinkedStack() {
  topPtr = nullptr;
}

template <class ItemType>
bool LinkedStack<ItemType>::isEmpty() const {
  return topPtr == nullptr;
}

template <class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newItem) {
  Node<ItemType>* newNode = new Node<ItemType>(newItem, topPtr);
  topPtr = newNode;
  newNode = nullptr;
  return true;
}

template <class ItemType>
bool LinkedStack<ItemType>::pop() {
  if (!isEmpty()) {
    Node<ItemType>* delNode = topPtr;
    topPtr = topPtr->getNext();
    delete delNode;
    delNode->setNext(nullptr);
    delNode = nullptr;
    return true;
  } else {
    return false;
  }
}

template <class ItemType>
ItemType LinkedStack<ItemType>::peek() const throw (out_of_range) {
  if(!isEmpty()) {
    return topPtr->getItem();
  } else {
    throw out_of_range("ERROR: There is nothing to display.");
  }
}

#include "LinkedQueue.h"

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue() {
  headPtr = nullptr;
  tailPtr = nullptr;
}

template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const {
  return headPtr == nullptr;
}

template<class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newItem) {
  Node<ItemType>* newNodePtr = new Node<ItemType>(newItem);
  if(isEmpty()) {
    headPtr = newNodePtr;
    tailPtr = newNodePtr;
  } else {
    tailPtr->setNext(newNodePtr);
    tailPtr = newNodePtr;
  }
  return true;
}

template<class ItemType>
bool LinkedQueue<ItemType>::dequeue() {
  bool removable = false;
  if(!isEmpty()) {
    Node<ItemType>* delNodePtr = headPtr;
    headPtr = headPtr->getNext();
    delNodePtr->setNext(nullptr);
    delete delNodePtr;
    delNodePtr = nullptr;
  }
  return removable;
}

template<class ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const {
  if(!isEmpty()) {
    return headPtr->getItem();
  }
  // needs to throw exception when isEmpty().
}

template<class ItemType>
void LinkedQueue<ItemType>::clear() {
  while(!isEmpty()) {
    dequeue();
  }
}

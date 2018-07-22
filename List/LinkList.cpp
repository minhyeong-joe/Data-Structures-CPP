#include "LinkList.h"

template<class ItemType>
LinkList<ItemType>::LinkList() {
  headPtr = nullptr;
  itemCount = 0;
}

template<class ItemType>
Node<ItemType>* LinkList<ItemType>::getNodeAt(const int& position) const throw(out_of_range){
  if(position>=1 && position <= itemCount) {
    Node<ItemType>* curPtr = headPtr;
    for(int i=1; i<position; i++) {
      curPtr = curPtr->getNext();
    }
    return curPtr;
  } else {
    throw out_of_range("Cannot access the node at the given position.");
  }
}

template<class ItemType>
bool LinkList<ItemType>::isEmpty() const {
  return itemCount == 0;
}

template<class ItemType>
int LinkList<ItemType>::getItemCount() const {
  return itemCount;
}

template<class ItemType>
void LinkList<ItemType>::reset() {
  while(!isEmpty()) {
    remove(1);
  }
}

template<class ItemType>
ItemType LinkList<ItemType>::getEntry(const int& position) const throw(out_of_range){
  if(position <= itemCount && position >= 1) {
    Node<ItemType>* curPtr = getNodeAt(position);
    return curPtr->getItem();
  } else {
    throw out_of_range("There is no entry in the given position.");
  }
}

template<class ItemType>
bool LinkList<ItemType>::insert(const int& position, const ItemType& newItem) {
  if(position > itemCount+1 || position < 1) {
    return false;
  } else {
    Node<ItemType>* newNodePtr = new Node<ItemType>(newItem);
    if(position == 1) {
      newNodePtr->setNext(headPtr);
      headPtr = newNodePtr;
    } else {
      Node<ItemType>* prevPtr = getNodeAt(position-1);
      newNodePtr->setNext(prevPtr->getNext());
      prevPtr->setNext(newNodePtr);
    }
    itemCount++;
    return true;
  }
}

template<class ItemType>
bool LinkList<ItemType>::remove(const int& position) {
  if(position > itemCount || position < 1) {
    return false;
  } else {
    Node<ItemType>* delNodePtr = nullptr;
    if(position == 1) {
      delNodePtr = headPtr;
      headPtr = headPtr->getNext();
    } else {
      Node<ItemType>* prevPtr = getNodeAt(position-1);
      delNodePtr = prevPtr->getNext();
      prevPtr->setNext(delNodePtr->getNext());
    }

    delNodePtr->setNext(nullptr);
    delete delNodePtr;
    delNodePtr = nullptr;
    itemCount--;
    return true;
  }
}

template<class ItemType>
bool LinkList<ItemType>::replace(const int& position, const ItemType& newItem) {
  if (remove(position)) {
    insert(position, newItem);
    return true;
  } else {
    return false;
  }
}

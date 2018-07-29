#include "LinkedList.h"

template<class ItemType>
LinkedList<ItemType>::LinkedList() {
  headPtr = nullptr;
  itemCount = 0;
}

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(const int& position) const throw(out_of_range){
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
bool LinkedList<ItemType>::isEmpty() const {
  return itemCount == 0;
}

template<class ItemType>
int LinkedList<ItemType>::getItemCount() const {
  return itemCount;
}

template<class ItemType>
void LinkedList<ItemType>::reset() {
  while(!isEmpty()) {
    remove(1);
  }
}

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(const int& position) const throw(out_of_range){
  if(position <= itemCount && position >= 1) {
    Node<ItemType>* curPtr = getNodeAt(position);
    return curPtr->getItem();
  } else {
    throw out_of_range("There is no entry in the given position.");
  }
}

template<class ItemType>
bool LinkedList<ItemType>::insert(const int& position, const ItemType& newItem) {
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
bool LinkedList<ItemType>::remove(const int& position) {
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
bool LinkedList<ItemType>::replace(const int& position, const ItemType& newItem) {
  if (remove(position)) {
    insert(position, newItem);
    return true;
  } else {
    return false;
  }
}

template<class ItemType>
void LinkedList<ItemType>::displayEntry() const {
  if(isEmpty()) {
    cout << "The list is empty." << endl;
  } else {
    Node<ItemType>* entryPtr = headPtr;
    for(int i = 1; i <= itemCount; i++) {
      cout << i << ". " << entryPtr->getItem() << endl;
      entryPtr = entryPtr->getNext();
    }
  }
  cout << endl;
};

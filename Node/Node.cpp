#include "Node.h"

template <class ItemType>
Node<ItemType>::Node() {
  next = nullptr;
}

template <class ItemType>
Node<ItemType>::Node(const ItemType& newItem) {
  item = newItem;
  next = nullptr;
}

template <class ItemType>
Node<ItemType>::Node(const ItemType& newItem, Node<ItemType>* nextPtr) {
  item = newItem;
  next = nextPtr;
}

template <class ItemType>
void Node<ItemType>::setItem(const ItemType& newItem) {
  item = newItem;
}

template <class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextPtr) {
  next = nextPtr;
}

template <class ItemType>
ItemType Node<ItemType>::getItem() {
  return item;
}

template <class ItemType>
Node<ItemType>* Node<ItemType>::getNext() {
  return next;
}

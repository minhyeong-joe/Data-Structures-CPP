#include "BSTNode.h"

template<class ItemType>
BSTNode<ItemType>::BSTNode() {
  leftChild = nullptr;
  rightChild = nullptr;
}

template<class ItemType>
BSTNode<ItemType>::BSTNode(const ItemType& anItem) {
  item = anItem;
  leftChild = nullptr;
  rightChild = nullptr;
}

template<class ItemType>
BSTNode<ItemType>::BSTNode(const ItemType& anItem, BSTNode<ItemType>* leftChild, BSTNode<ItemType>* rightChild) {
  item = anItem;
  this->leftChild = leftChild;
  this->rightChild = rightChild;
}

template<class ItemType>
void BSTNode<ItemType>::setItem(const ItemType& anItem) {
  item = anItem;
}

template<class ItemType>
ItemType BSTNode<ItemType>::getItem() const {
  return item;
}

template<class ItemType>
bool BSTNode<ItemType>::isLeaf() const {
  bool isLeaf = false;
  if(leftChild == nullptr && rightChild == nullptr) {
    isLeaf = true;
  }
  return isLeaf;
}

template<class ItemType>
BSTNode<ItemType>* BSTNode<ItemType>::getLeftChild() const {
  return leftChild;
}

template<class ItemType>
BSTNode<ItemType>* BSTNode<ItemType>::getRightChild() const {
  return rightChild;
}

template<class ItemType>
void BSTNode<ItemType>::setLeftChild(BSTNode<ItemType>* leftChildPtr) {
  leftChild = leftChildPtr;
}

template<class ItemType>
void BSTNode<ItemType>::setRightChild(BSTNode<ItemType>* rightChildPtr) {
  rightChild = rightChildPtr;
}

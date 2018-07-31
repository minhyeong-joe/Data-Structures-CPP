#ifndef _BST_NODE_H
#define _BST_NODE_H

template <class ItemType>
class BSTNode {
private:
  ItemType item;
  BSTNode<ItemType>* leftChild;
  BSTNode<ItemType>* rightChild;

public:
  BSTNode();
  BSTNode(const ItemType& anItem);
  BSTNode(const ItemType& anItem, BSTNode<ItemType>* leftChild, BSTNode<ItemType>* rightChild);

  void setItem(const ItemType& anItem);
  ItemType getItem() const;

  bool isLeaf() const;

  BSTNode<ItemType>* getLeftChild() const;
  BSTNode<ItemType>* getRightChild() const;

  void setLeftChild(BSTNode<ItemType>* leftChildPtr);
  void setRightChild(BSTNode<ItemType>* rightChildPtr);
};

#include "BSTNode.cpp"
#endif

#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

#include "../BinaryTree/BSTNode.h"
#include<stdexcept>
#include<iostream>

using namespace std;

template<class ItemType>
class BinarySearchTree {
private:
  BSTNode<ItemType>* rootPtr;
protected:
  // ===========================================================================
  // Helper functions (recursive)
  // ===========================================================================
  int getHeightHelper(BSTNode<ItemType>* subTreePtr) const;
  int getNodeCountHelper(BSTNode<ItemType>* subTreePtr) const;
  void destroyTree(BSTNode<ItemType>* subTreePtr);

  BSTNode<ItemType>* insertInorder(BSTNode<ItemType>* subTreePtr, BSTNode<ItemType>* newNodePtr);
  BSTNode<ItemType>* removeValue(BSTNode<ItemType>* subTreePtr, const ItemType target);
  BSTNode<ItemType>* findNode(BSTNode<ItemType>* subTreePtr, const ItemType& target) const;

  BSTNode<ItemType>* copyTree(const BSTNode<ItemType>* treePtr) const;

  // traversal helper
  void preorder(BSTNode<ItemType>* subTreePtr) const;
  void inorder(BSTNode<ItemType>* subTreePtr) const;
  void postorder(BSTNode<ItemType>* subTreePtr) const;

public:
  // ===========================================================================
  // Constructors & Destructor
  // ===========================================================================
  BinarySearchTree();
  BinarySearchTree(const ItemType& rootItem);
  BinarySearchTree(const BinarySearchTree<ItemType>* tree);
  virtual ~BinarySearchTree();

  // ===========================================================================
  // Public Methods
  // ===========================================================================
  bool isEmpty() const;
  int getHeight() const;
  int getNodeCount() const;
  ItemType getRootData() const;
  void setRootData(const ItemType& newData);
  bool add(const ItemType& newData);
  bool remove(const ItemType& aData);
  void clear();
  bool contains(const ItemType& target) const;

  void printPreorder() const;
  void printInorder() const;
  void printPostorder() const;
};

#include "BinarySearchTree.cpp"
#endif

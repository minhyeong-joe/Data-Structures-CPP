#ifndef _LINKED_BINARY_TREE_H
#define _LINKED_BINARY_TREE_H

#include "BinaryInterface.h"
#include "BSTNode.h"
#include <stdexcept>
using namespace std;

template<class ItemType>
class LinkedBinaryTree : public BinaryInterface<ItemType> {
private:
  BSTNode<ItemType>* rootPtr;

protected:
  // ===========================================================================
  // Helper functions (recursive functions)
  // ===========================================================================
  int getHeightHelper(BSTNode<ItemType>* subTreePtr) const;
  int getNodeCountHelper(BSTNode<ItemType>* subTreePtr) const;
  void destroyTree(BSTNode<ItemType>* subTreePtr);

  BSTNode<ItemType>* balancedAdd(BSTNode<ItemType>* subTreePtr, BSTNode<ItemType>* newNodePtr);
  // BSTNode<ItemType>* removeValue(BSTNode<ItemType>* subTreePtr, const ItemType target);
  // BSTNode<ItemType>* moveValuesUpTree(BSTNode<ItemType>* subTreePtr);
  BSTNode<ItemType>* findNode(BSTNode<ItemType>* subTreePtr, const ItemType& target) const;

  BSTNode<ItemType>* copyTree(const BSTNode<ItemType>* treePtr) const;

  // transversal helper
  void preorder(BSTNode<ItemType>* subTreePtr) const;
  void inorder(BSTNode<ItemType>* subTreePtr) const;
  void postorder(BSTNode<ItemType>* subTreePtr) const;
public:
  // ===========================================================================
  // Constructors & Destructor
  // ===========================================================================
  LinkedBinaryTree();
  LinkedBinaryTree(const ItemType& rootItem);
  LinkedBinaryTree(const ItemType& rootItem, const BSTNode<ItemType>* leftChildPtr, BSTNode<ItemType>* rightChildPtr);
  LinkedBinaryTree(const LinkedBinaryTree<ItemType>* tree);
  virtual ~LinkedBinaryTree();

  // ===========================================================================
  // Public methods from interface
  // ===========================================================================
  bool isEmpty() const;
  int getHeight() const;
  int getNodeCount() const;
  ItemType getRoot() const;
  void setRoot(const ItemType& newItem);
  bool add(const ItemType& newItem);
  bool remove(const ItemType& delItem);
  void clear();
  ItemType find(const ItemType& targetItem) const;
  bool contains(const ItemType& targetItem) const;
  void preOrder() const;
  void inOrder() const;
  void postOrder() const;
};

#include "LinkedBinaryTree.cpp"
#endif

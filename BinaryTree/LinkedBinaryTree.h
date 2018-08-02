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

  // ===========================================================================
  // Helper functions (recursive functions)
  // ===========================================================================
  int getHeightHelper(BSTNode<ItemType>* subTreePtr) const;
  int getNodeCountHelper(BSTNed<ItemType>* subTreePtr) const;
  void destroyTree(BSTNode<ItemType>* subTreePtr);

  BSTNode<ItemType>* balancedAdd(BSTNode<ItemType>* subTreePtr, BSTNode<ItemType>* newNodePtr);
  BSTNode<ItemType>* removeValue(BSTNode<ItemType>* subTreePtr, const ItemType target, bool& success);
  BSTNode<ItemType>* moveValuesUpTree(BSTNode<ItemType>* subTreePtr);
  BSTNode<ItemType>* findNode(BSTNode<ItemType>* subTreePtr, const ItemType& target, bool& success) const;

  // transversal helper
  void preorder(void visit(ItemType&), BSTNode<ItemType>* subTreePtr) const;
  void inorder(void visit(ItemType&), BSTNode<ItemType>* subTreePtr) const;
  void postorder(void visit(ItemType&), BSTNode<ItemType>* subTreePtr) const;
public:
  // ===========================================================================
  // Constructors & Destructor
  // ===========================================================================
  LinkedBinaryTree();
  LinkedBinaryTree(const LinkedBinaryTree<ItemType>& aTree);
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
  void preOrder(void visit(ItemType&)) const;
  void inOrder(void visit(ItemType&)) const;
  void postOrder(void visit(ItemType&)) const;
};

#include "LinkedBinaryTree.cpp"
#endif

#include "LinkedBinaryTree.h"

// =============================================================================
// Constructors & Destructor
// =============================================================================
template<class ItemType>
LinkedBinaryTree<ItemType>::LinkedBinaryTree() {
  rootPtr = nullptr;
}

template<class ItemType>
LinkedBinaryTree<ItemType>::LinkedBinaryTree(const ItemType& rootItem) {
  rootPtr = new BSTNode<ItemType>(rootItem, nullptr, nullptr);
}

template<class ItemType>
LinkedBinaryTree<ItemType>::LinkedBinaryTree(const ItemType& rootItem, const BSTNode<ItemType>* leftChildPtr, BSTNode<ItemType>* rightChildPtr) {
  rootPtr = new BSTNode<ItemType>(rootItem, copyTree(leftChildPtr), copyTree(rightChildPtr));
}

template<class ItemType>
LinkedBinaryTree<ItemType>::LinkedBinaryTree(const LinkedBinaryTree<ItemType>* tree) {
  copyTree(tree->rootPtr);
}

template<class ItemType>
LinkedBinaryTree<ItemType>::~LinkedBinaryTree() {
  destroyTree(rootPtr);
}

// =============================================================================
// Helper functions
// =============================================================================
template<class ItemType>
int LinkedBinaryTree<ItemType>::getHeightHelper(BSTNode<ItemType>* subTreePtr) const {
  if (subTreePtr != nullptr) {
    return 1 + max(getHeightHelper(subTreePtr->getLeftChild()), getHeightHelper(subTreePtr->getRightChild()));
  } else {
    return 0;
  }
}

template<class ItemType>
int LinkedBinaryTree<ItemType>::getNodeCountHelper(BSTNode<ItemType>* subTreePtr) const {
  return 0;
}

template<class ItemType>
void LinkedBinaryTree<ItemType>::destroyTree(BSTNode<ItemType>* subTreePtr) {
  if (subTreePtr != nullptr) {
    destroyTree(subTreePtr->getLeftChild());
    destroyTree(subTreePtr->getRightChild());
    delete subTreePtr;
  }
}

template<class ItemType>
BSTNode<ItemType>* LinkedBinaryTree<ItemType>::balancedAdd(BSTNode<ItemType>* subTreePtr, BSTNode<ItemType>* newNodePtr) {
  return new BSTNode<ItemType>();
}

template<class ItemType>
BSTNode<ItemType>* LinkedBinaryTree<ItemType>::removeValue(BSTNode<ItemType>* subTreePtr, const ItemType target, bool& success) {
  return new BSTNode<ItemType>();
}

template<class ItemType>
BSTNode<ItemType>* LinkedBinaryTree<ItemType>::moveValuesUpTree(BSTNode<ItemType>* subTreePtr) {
  return new BSTNode<ItemType>();
}

template<class ItemType>
BSTNode<ItemType>* LinkedBinaryTree<ItemType>::findNode(BSTNode<ItemType>* subTreePtr, const ItemType& target, bool& success) const {
  return new BSTNode<ItemType>();
}

template<class ItemType>
BSTNode<ItemType>* LinkedBinaryTree<ItemType>::copyTree(const BSTNode<ItemType>* treePtr) const {
  BSTNode<ItemType>* newTreePtr = nullptr;
  if(treePtr != nullptr) {
    newTreePtr = new BSTNode<ItemType>(treePtr->getItem(), nullptr, nullptr);
    newTreePtr->setLeftChild(copyTree(treePtr->getLeftChild()));
    newTreePtr->setRightChild(copyTree(treePtr->getRightChild()));
  } else {
    return newTreePtr;
  }
}

template<class ItemType>
void LinkedBinaryTree<ItemType>::preorder(void visit(ItemType&), BSTNode<ItemType>* subTreePtr) const {

}

template<class ItemType>
void LinkedBinaryTree<ItemType>::inorder(void visit(ItemType&), BSTNode<ItemType>* subTreePtr) const {

}

template<class ItemType>
void LinkedBinaryTree<ItemType>::postorder(void visit(ItemType&), BSTNode<ItemType>* subTreePtr) const {

}

// =============================================================================
// Public Methods
// =============================================================================
template<class ItemType>
bool LinkedBinaryTree<ItemType>::isEmpty() const {
  return rootPtr == nullptr;
}

template<class ItemType>
int LinkedBinaryTree<ItemType>::getHeight() const {
  return getHeightHelper(rootPtr);
}

template<class ItemType>
int LinkedBinaryTree<ItemType>::getNodeCount() const {
  return 0;
}

template<class ItemType>
ItemType LinkedBinaryTree<ItemType>::getRoot() const {
}

template<class ItemType>
void LinkedBinaryTree<ItemType>::setRoot(const ItemType& newItem) {

}

template<class ItemType>
bool LinkedBinaryTree<ItemType>::add(const ItemType& newItem) {
  return false;
}

template<class ItemType>
bool LinkedBinaryTree<ItemType>::remove(const ItemType& delItem) {
  return false;
}

template<class ItemType>
void LinkedBinaryTree<ItemType>::clear() {

}

template<class ItemType>
ItemType LinkedBinaryTree<ItemType>::find(const ItemType& targetItem) const {
}

template<class ItemType>
bool LinkedBinaryTree<ItemType>::contains(const ItemType& targetItem) const {
  return false;
}

template<class ItemType>
void LinkedBinaryTree<ItemType>::preOrder(void visit(ItemType&)) const {

}

template<class ItemType>
void LinkedBinaryTree<ItemType>::inOrder(void visit(ItemType&)) const {

}

template<class ItemType>
void LinkedBinaryTree<ItemType>::postOrder(void visit(ItemType&)) const {

}

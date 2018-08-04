#include "BinarySearchTree.h"

// =============================================================================
// Constructors & Destructor
// =============================================================================
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() {
  rootPtr = nullptr;
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem) {
  rootPtr = new BSTNode<ItemType>(rootItem, nullptr, nullptr);
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>* tree) {
  rootPtr = copyTree(tree->rootPtr);
}

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree() {
  destroyTree(rootPtr);
}

// =============================================================================
// Helper functions
// =============================================================================
template<class ItemType>
int BinarySearchTree<ItemType>::getHeightHelper(BSTNode<ItemType>* subTreePtr) const {
  if (subTreePtr != nullptr) {
    return 1 + max(getHeightHelper(subTreePtr->getLeftChild()), getHeightHelper(subTreePtr->getRightChild()));
  } else {
    return 0;
  }
}

template<class ItemType>
int BinarySearchTree<ItemType>::getNodeCountHelper(BSTNode<ItemType>* subTreePtr) const {
  if (subTreePtr != nullptr) {
    return 1 + getNodeCountHelper(subTreePtr->getLeftChild()) + getNodeCountHelper(subTreePtr->getRightChild());
  } else {
    return 0;
  }
}

template<class ItemType>
void BinarySearchTree<ItemType>::destroyTree(BSTNode<ItemType>* subTreePtr) {
  if (subTreePtr != NULL) {
    destroyTree(subTreePtr->getLeftChild());
    destroyTree(subTreePtr->getRightChild());
    delete subTreePtr;
  }
}

template<class ItemType>
BSTNode<ItemType>* BinarySearchTree<ItemType>::insertInorder(BSTNode<ItemType>* subTreePtr, BSTNode<ItemType>* newNodePtr) {
  if (subTreePtr == nullptr) {
    return newNodePtr;
  } else {
    BSTNode<ItemType>* temp;
    if (newNodePtr->getItem() < subTreePtr->getItem()) {
      temp = insertInorder(subTreePtr->getLeftChild(), newNodePtr);
      subTreePtr->setLeftChild(temp);
    } else {
      temp = insertInorder(subTreePtr->getRightChild(), newNodePtr);
      subTreePtr->setRightChild(temp);
    }
  }
}

template<class ItemType>
BSTNode<ItemType>* BinarySearchTree<ItemType>::removeValue(BSTNode<ItemType>* subTreePtr, const ItemType target) {
  BSTNode<ItemType>* temp;
  if (subTreePtr == nullptr) {
    return nullptr;
  } else if (subTreePtr->getItem() == target) {
    subTreePtr = removeNode(subTreePtr);
    return subTreePtr;
  } else if (subTreePtr->getItem() > target) {
    temp = removeValue(subTreePtr->getLeftChild(), target);
    subTreePtr->setLeftChild(temp);
    return subTreePtr;
  } else if (subTreePtr->getItem() < target) {
    temp = removeValue(subTreePtr->getRightChild(), target);
    subTreePtr->setRightChild(temp);
    return subTreePtr;
  }
}

template<class ItemType>
BSTNode<ItemType>* BinarySearchTree<ItemType>::removeNode(BSTNode<ItemType>* nodePtr) {
  if( nodePtr->getLeftChild() == nullptr && nodePtr->getRightChild() == nullptr) {
    delete nodePtr;
    nodePtr = nullptr;
    return nodePtr;
  } else if ( (nodePtr->getLeftChild() != nullptr && nodePtr->getRightChild() == nullptr) || (nodePtr->getLeftChild() == nullptr && nodePtr->getRightChild() != nullptr)) {
    BSTNode<ItemType>* connectNodePtr;
    if ( nodePtr->getRightChild() == nullptr && nodePtr->getLeftChild() != nullptr) {
      connectNodePtr = nodePtr->getLeftChild();
    } else {
      connectNodePtr = nodePtr->getRightChild();
    }
    delete nodePtr;
    nodePtr = nullptr;
    return connectNodePtr;
  } else {
    BSTNode<ItemType>* temp;
    BSTNode<ItemType>* rightChild = nodePtr->getRightChild();
    BSTNode<ItemType>* leftMostNodePtr = leftMostNode(rightChild);
    nodePtr->setItem(leftMostNodePtr->getItem());
    nodePtr->setRightChild(rightChild);
    removeValue(rightChild, leftMostNodePtr->getItem());
    return nodePtr;
  }
}

template<class ItemType>
BSTNode<ItemType>* BinarySearchTree<ItemType>::leftMostNode(BSTNode<ItemType>* nodePtr) {
  if ( nodePtr->getLeftChild() == nullptr) {
    return nodePtr;
  } else {
    return leftMostNode(nodePtr->getLeftChild());
  }
}

template<class ItemType>
BSTNode<ItemType>* BinarySearchTree<ItemType>::removeLeftMostNode(BSTNode<ItemType>* nodePtr) {
  if (nodePtr->getLeftChild() == nullptr) {
    // cout << nodePtr->getItem() << endl;
    return removeNode(nodePtr);
  } else {
    // cout << "removeLeftMost recursion" << endl;
    return removeLeftMostNode(nodePtr->getLeftChild());
  }
}

template<class ItemType>
BSTNode<ItemType>* BinarySearchTree<ItemType>::findNode(BSTNode<ItemType>* subTreePtr, const ItemType& target) const {
  if (subTreePtr == nullptr) {
    return nullptr;
  } else if (subTreePtr->getItem() == target) {
    return subTreePtr;
  } else if (subTreePtr->getItem() > target) {
    return findNode(subTreePtr->getLeftChild(), target);
  } else {
    return findNode(subTreePtr->getRightChild(), target);
  }
}

template<class ItemType>
BSTNode<ItemType>* BinarySearchTree<ItemType>::copyTree(const BSTNode<ItemType>* treePtr) const {
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
void BinarySearchTree<ItemType>::preorder(BSTNode<ItemType>* subTreePtr) const {
  if (subTreePtr == nullptr) {
    return;
  }
  cout << subTreePtr->getItem() << " ";
  preorder(subTreePtr->getLeftChild());
  preorder(subTreePtr->getRightChild());
}

template<class ItemType>
void BinarySearchTree<ItemType>::inorder(BSTNode<ItemType>* subTreePtr) const {
  if (subTreePtr == nullptr) {
    return;
  }
  inorder(subTreePtr->getLeftChild());
  cout << subTreePtr->getItem() << " ";
  inorder(subTreePtr->getRightChild());
}

template<class ItemType>
void BinarySearchTree<ItemType>::postorder(BSTNode<ItemType>* subTreePtr) const {
  if (subTreePtr == nullptr) {
    return;
  }
  postorder(subTreePtr->getLeftChild());
  postorder(subTreePtr->getRightChild());
  cout << subTreePtr->getItem() << " ";
}

// =============================================================================
// Public Methods
// =============================================================================
template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const {
  return rootPtr == nullptr;
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const {
  return getHeightHelper(rootPtr);
}

template<class ItemType>
int BinarySearchTree<ItemType>::getNodeCount() const {
  return getNodeCountHelper(rootPtr);
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const {
  ItemType rootData = rootPtr->getItem();
  return rootData;
}

template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newData) {
  rootPtr->setItem(newData);
}

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newData) {
  BSTNode<ItemType>* newNodePtr = new BSTNode<ItemType>(newData);
  rootPtr = insertInorder(rootPtr, newNodePtr);
  return true;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& aData) {
  rootPtr = removeValue(rootPtr, aData);
  return true;
}

template<class ItemType>
void BinarySearchTree<ItemType>::clear() {
  destroyTree(rootPtr);
}

template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& target) const {
  bool contain = false;
  if (findNode(rootPtr, target) != nullptr) {
    contain = true;
  }
  return contain;
}

template<class ItemType>
void BinarySearchTree<ItemType>::printPreorder() const {
  preorder(rootPtr);
  cout << endl;
}

template<class ItemType>
void BinarySearchTree<ItemType>::printInorder() const {
  inorder(rootPtr);
  cout << endl;
}

template<class ItemType>
void BinarySearchTree<ItemType>::printPostorder() const {
  postorder(rootPtr);
  cout << endl;
}

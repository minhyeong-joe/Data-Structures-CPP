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
  rootPtr = copyTree(tree->rootPtr);
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
  if (subTreePtr != nullptr) {
    return 1 + getNodeCountHelper(subTreePtr->getLeftChild()) + getNodeCountHelper(subTreePtr->getRightChild());
  } else {
    return 0;
  }
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
  if (subTreePtr != nullptr) {
    BSTNode<ItemType>* leftChild = subTreePtr->getLeftChild();
    BSTNode<ItemType>* rightChild = subTreePtr->getRightChild();
    int leftHeight = getHeightHelper(leftChild);
    int rightHeight = getHeightHelper(rightChild);
    if (leftHeight > rightHeight) {
      rightChild = balancedAdd(rightChild, newNodePtr);
      subTreePtr->setRightChild(rightChild);
    } else {
      leftChild = balancedAdd(leftChild, newNodePtr);
      subTreePtr->setLeftChild(leftChild);
    }
    return subTreePtr;
  } else {
    return newNodePtr;
  }
}

// template<class ItemType>
// BSTNode<ItemType>* LinkedBinaryTree<ItemType>::removeValue(BSTNode<ItemType>* subTreePtr, const ItemType target) {
//   BSTNode<ItemType>* nodeToDelete = findNode(rootPtr, target);
//   if (nodeToDelete->getLeftChild() == nullptr && nodeToDelete->getRightChild() == nullptr) {
//     delete nodeToDelete;
//     nodeToDelete = nullptr;
//     return subTreePtr;
//   }
// }

// template<class ItemType>
// BSTNode<ItemType>* LinkedBinaryTree<ItemType>::moveValuesUpTree(BSTNode<ItemType>* subTreePtr) {
//   return new BSTNode<ItemType>();
// }

template<class ItemType>
BSTNode<ItemType>* LinkedBinaryTree<ItemType>::findNode(BSTNode<ItemType>* subTreePtr, const ItemType& target) const {
  if (subTreePtr == nullptr) {
    return nullptr;
  } else if (subTreePtr->getItem() == target) {
    return subTreePtr;
  } else {
    BSTNode<ItemType>* leftChild = findNode(subTreePtr->getLeftChild(), target);
    BSTNode<ItemType>* rightChild = findNode(subTreePtr->getRightChild(), target);
    if (leftChild) {
      return leftChild;
    } else {
      return rightChild;
    }
  }
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
void LinkedBinaryTree<ItemType>::preorder(BSTNode<ItemType>* subTreePtr) const {
  if (subTreePtr == nullptr) {
    return;
  }
  cout << subTreePtr->getItem() << " ";
  preorder(subTreePtr->getLeftChild());
  preorder(subTreePtr->getRightChild());
}

template<class ItemType>
void LinkedBinaryTree<ItemType>::inorder(BSTNode<ItemType>* subTreePtr) const {
  if (subTreePtr == nullptr) {
    return;
  }
  inorder(subTreePtr->getLeftChild());
  cout << subTreePtr->getItem() << " ";
  inorder(subTreePtr->getRightChild());
}

template<class ItemType>
void LinkedBinaryTree<ItemType>::postorder(BSTNode<ItemType>* subTreePtr) const {
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
bool LinkedBinaryTree<ItemType>::isEmpty() const {
  return rootPtr == nullptr;
}

template<class ItemType>
int LinkedBinaryTree<ItemType>::getHeight() const {
  return getHeightHelper(rootPtr);
}

template<class ItemType>
int LinkedBinaryTree<ItemType>::getNodeCount() const {
  return getNodeCountHelper(rootPtr);
}

template<class ItemType>
ItemType LinkedBinaryTree<ItemType>::getRoot() const {
  ItemType rootData = rootPtr->getItem();
  return rootData;
}

template<class ItemType>
void LinkedBinaryTree<ItemType>::setRoot(const ItemType& newItem) {
  rootPtr->setItem(newItem);
}

template<class ItemType>
bool LinkedBinaryTree<ItemType>::add(const ItemType& newItem) {
  BSTNode<ItemType>* newNodePtr = new BSTNode<ItemType>(newItem);
  rootPtr = balancedAdd(rootPtr, newNodePtr);
  return true;
}

template<class ItemType>
bool LinkedBinaryTree<ItemType>::remove(const ItemType& delItem) {
  BSTNode<ItemType>* delNode = findNode(rootPtr, delItem);
  if (delNode == nullptr) {
    return false;
  } else if (delNode->getLeftChild() == nullptr && delNode->getRightChild() == nullptr) {
    delete delNode;
    delNode = nullptr;
    return true;
  } else if (delNode->getLeftChild() == nullptr && delNode->getRightChild() != nullptr) {

  } else if (delNode->getLeftChild() != nullptr && delNode->getRightChild() == nullptr) {

  } else {

  }
}

template<class ItemType>
void LinkedBinaryTree<ItemType>::clear() {

}

template<class ItemType>
ItemType LinkedBinaryTree<ItemType>::find(const ItemType& targetItem) const {
  BSTNode<ItemType>* targetNode = findNode(rootPtr, targetItem);
  return targetNode->getItem();
}

template<class ItemType>
bool LinkedBinaryTree<ItemType>::contains(const ItemType& targetItem) const {
  bool contain = false;
  if (findNode(rootPtr, targetItem) != nullptr) {
    contain = true;
  }
  return contain;
}

template<class ItemType>
void LinkedBinaryTree<ItemType>::preOrder() const {
  preorder(rootPtr);
  cout << endl;
}

template<class ItemType>
void LinkedBinaryTree<ItemType>::inOrder() const {
  inorder(rootPtr);
  cout << endl;
}

template<class ItemType>
void LinkedBinaryTree<ItemType>::postOrder() const {
  postorder(rootPtr);
  cout << endl;
}

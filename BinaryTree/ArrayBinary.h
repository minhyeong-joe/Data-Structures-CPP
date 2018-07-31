#ifndef _ARRAY_BINARY_H
#define _ARRAY_BINARY_H

#include "BinaryInterface.h"

template<class ItemType>
class ArrayBinary : public BinaryInterface<ItemType> {
private:
  static const int MAX = 30;
  ItemType* data;
  int dataCount;

  // Helper functions
  // finds and returns the index of left-child
  int leftChild(const int& root);
  // finds and returns the index of right-child
  int rightChild(const int& root);
  // finds and returns the index of parent
  int parent(const int& child);

public:
  ArrayBinary();

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

#include "ArrayBinary.cpp"
#endif

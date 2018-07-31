#ifndef _BINARY_INTERFACE_H
#define _BINARY_INTERFACE_H

template<class ItemType>
class BinaryInterface {
public:
  virtual bool isEmpty() const = 0;
  virtual int getHeight() const = 0;
  virtual int getNodeCount() const = 0;
  virtual ItemType getRoot() const = 0;
  virtual void setRoot(const ItemType& newItem) = 0;
  virtual bool add(const ItemType& newItem) = 0;
  virtual bool remove(const ItemType& delItem) = 0;
  virtual void clear() = 0;
  virtual ItemType find(const ItemType& targetItem) const = 0;
  virtual bool contains(const ItemType& targetItem) const = 0;
  virtual void preOrder(void visit(ItemType&)) const = 0;
  virtual void inOrder(void visit(ItemType&)) const = 0;
  virtual void postOrder(void visit(ItemType&)) const = 0;
};

#endif

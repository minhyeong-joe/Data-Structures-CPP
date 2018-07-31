#ifndef _HEAP_INTERFACE_H
#define _HEAP_INTERFACE_H

template <class ItemType>
class HeapInterface {
public:
  virtual bool isEmpty() const = 0;
  virtual int getNodeCount() const = 0;
  virtual int getHeight() const = 0;
  virtual ItemType peekTop() const = 0;
  virtual bool add(const ItemType& newItem) = 0;
  virtual bool remove() = 0;
  virtual void clear() = 0;
};

#endif

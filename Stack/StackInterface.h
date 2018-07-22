#ifndef _STACK_INTERFACE_H
#define _STACK_INTERFACE_H

template <class ItemType>
class StackInterface{
public:
  virtual bool isEmpty() const = 0;
  virtual bool push(const ItemType& newItem) = 0;
  virtual bool pop() = 0;
  virtual ItemType peek() const = 0;
};

#endif

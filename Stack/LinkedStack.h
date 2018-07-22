#ifndef _LINKED_STACK_H
#define _LINKED_STACK_H

#include "StackInterface.h"
#include "../Node/Node.h"
#include "stdexcept"
using namespace std;

template <class ItemType>
class LinkedStack : public StackInterface<ItemType> {
private:
  Node<ItemType>* topPtr;
public:
  LinkedStack();

  bool isEmpty() const;
  bool push(const ItemType& newItem);
  bool pop();
  ItemType peek() const throw (out_of_range);
};

#include "LinkedStack.cpp"
#endif

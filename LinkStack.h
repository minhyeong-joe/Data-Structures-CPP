#ifndef _LINK_STACK_H
#define _LINK_STACK_H

#include "Node.h"
#include "stdexcept"
using namespace std;

template <class ItemType>
class LinkStack {
private:
  Node<ItemType>* topPtr;
public:
  LinkStack();

  bool isEmpty() const;
  bool push(const ItemType& newItem);
  bool pop();
  ItemType peek() const throw (out_of_range);
};

#include "LinkStack.cpp"
#endif

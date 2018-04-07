#ifndef _ARRAY_STACK_H
#define _ARRAY_STACK_H

#include "stdexcept"
using namespace std;

const int MAX = 10;

template <class ItemType>
class ArrayStack {
private:
  ItemType items[MAX];
  int top;
public:
  ArrayStack();

  bool isEmpty() const;
  bool push(const ItemType& newItem);
  bool pop();
  ItemType peek() const throw (out_of_range);
};

#include "ArrayStack.cpp"
#endif

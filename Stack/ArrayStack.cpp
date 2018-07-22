#include "ArrayStack.h"

template <class ItemType>
ArrayStack<ItemType>::ArrayStack() {
  top = -1;
}

template <class ItemType>
bool ArrayStack<ItemType>::isEmpty() const {
  return top < 0;
}

template <class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newItem) {
  if(top == MAX-1) {
    return false;
  } else {
    top++;
    items[top] = newItem;
    return true;
  }
}

template <class ItemType>
bool ArrayStack<ItemType>::pop() {
  if (isEmpty()) {
    return false;
  } else {
    top--;
    return true;
  }
}

template <class ItemType>
ItemType ArrayStack<ItemType>::peek() const throw(out_of_range){
  if(!isEmpty()) {
    return items[top];
  } else {
    throw out_of_range("There is nothing to display.");
  }
}

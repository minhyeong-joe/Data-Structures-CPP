#include "ArrayQueue.h"

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue() {
  items = new ItemType[MAX];
  front = 0;
  back = 0;
  count = 0;
}

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const {
  return count == 0;
}

template<class ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType& newItem) {
  bool inserted = false;
  if(count < MAX) {
    items[back] = newItem;
    back = (back+1) % MAX;
    count++;
    inserted = true;
  }
  return inserted;
}

template<class ItemType>
bool ArrayQueue<ItemType>::dequeue() {
  bool removable = false;
  if(!isEmpty()) {
    front = (front+1) % MAX;
    count--;
    removable = true;
  }
  return removable;
}

template<class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const {
  if(!isEmpty()) {
    return items[front];
  }
  // needs to throw exception when isEmpty().
}

template<class ItemType>
void ArrayQueue<ItemType>::clear() {
  while(!isEmpty()) {
    dequeue();
  }
}

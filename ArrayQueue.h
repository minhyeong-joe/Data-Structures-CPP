#ifndef _ARRAY_QUEUE_H
#define _ARRAY_QUEUE_H

#include "QueueInterface.h"

template<class ItemType>
class ArrayQueue : public QueueInterface<ItemType> {
private:
  const int MAX = 10;
  ItemType* items;
  int front;
  int back;
  int count;
public:
  ArrayQueue();
  bool isEmpty() const;
  bool enqueue(const ItemType& newItem);
  bool dequeue();
  ItemType peekFront() const;
  void clear();
};

#include "ArrayQueue.cpp"
#endif

#ifndef _LINKED_QUEUE_H
#define _LINKED_QUEUE_H

#include "QueueInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedQueue : public QueueInterface<ItemType> {
private:
  Node<ItemType>* headPtr;
  Node<ItemType>* tailPtr;
public:
  LinkedQueue();
  bool isEmpty() const;
  bool enqueue(const ItemType& newItem);
  bool dequeue();
  ItemType peekFront() const;
  void clear();
};

#include "LinkedQueue.cpp"
#endif

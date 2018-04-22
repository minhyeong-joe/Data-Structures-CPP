#ifndef _QUEUE_INTERFACE_H
#define _QUEUE_INTERFACE_H

template<class ItemType>
class QueueInterface {
public:
  /** Checks if there is any data in the queue data structure.
  @return true if the queue is empty. */
  virtual bool isEmpty() const = 0;

  /** Inserts a new data into the queue.
  @param newItem is the new data that is going to be inserted.
  @post newItem is inserted to the BACK of the queue.
  @return true if the insertion was successful, and false if the queue is full and the insertion was not successful. */
  virtual bool enqueue(const ItemType& newItem) = 0;

  /** Removes a data from the queue.
  @pre The queue has at least one data in it.
  @post A data is removed from the FRONT of the queue.
  @return true if the removal was successful. */
  virtual bool dequeue() = 0;

  /** Returns an item from the queue.
  @pre The queue has at least one data in it.
  @return The data item at the FRONTMOST position in the queue. */
  virtual ItemType peekFront() const = 0;

  /** Clears the queue.
  @post Removes all data items in the queue. */
  virtual void clear() = 0;
};

#endif

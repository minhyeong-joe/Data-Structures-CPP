#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include "ListInterface.h"
#include "../Node/Node.h"
#include <stdexcept>
#include <iostream>
using namespace std;

template <class ItemType>
class LinkedList : public ListInterface<ItemType> {
private:
  Node<ItemType>* headPtr;
  int itemCount;

  Node<ItemType>* getNodeAt(const int& position) const throw(out_of_range);
public:
  LinkedList();

  bool isEmpty() const;
  int getItemCount() const;
  void reset();
  ItemType getEntry(const int& position) const throw(out_of_range);
  bool insert(const int& position, const ItemType& newItem);
  bool remove(const int& position);
  bool replace(const int& position, const ItemType& newItem);
  void displayEntry() const;
};

#include "LinkedList.cpp"
#endif

#ifndef _LINK_LIST_H
#define _LINK_LIST_H

#include <stdexcept>
#include "Node.h"
using namespace std;

template <class ItemType>
class LinkList {
private:
  Node<ItemType>* headPtr;
  int itemCount;

  Node<ItemType>* getNodeAt(const int& position) const throw(out_of_range);
public:
  LinkList();

  bool isEmpty() const;
  int getItemCount() const;
  void reset();
  ItemType getEntry(const int& position) const throw(out_of_range);
  bool insert(const int& position, const ItemType& newItem);
  bool remove(const int& position);
  bool replace(const int& position, const ItemType& newItem);
};

#include "LinkList.cpp"
#endif

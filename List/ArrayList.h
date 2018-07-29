#ifndef _ARRAY_LIST_H
#define _ARRAY_LIST_H

#include "ListInterface.h"
#include "stdexcept"
using namespace std;

template <class ItemType>
class ArrayList : public ListInterface<ItemType> {
private:
  static const int MAX = 10;
  ItemType items[MAX];
  int itemCount;
public:
  ArrayList();

  bool isEmpty() const;
  int getItemCount() const;
  void reset();
  ItemType getEntry(const int& position) const throw(out_of_range);
  bool insert(const int& position, const ItemType& newItem);
  bool remove(const int& position);
  bool replace(const int& position, const ItemType& newItem);
  void displayEntry() const;
};

#include "ArrayList.cpp"
#endif

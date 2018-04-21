#include "ArrayList.h"

template<class ItemType>
ArrayList<ItemType>::ArrayList() {
  itemCount = 0;
}

template<class ItemType>
bool ArrayList<ItemType>::isEmpty() const {
  return itemCount == 0;
}

template<class ItemType>
int ArrayList<ItemType>::getItemCount() const {
  return itemCount;
}

template<class ItemType>
void ArrayList<ItemType>::reset() {
  itemCount = 0;
}

template<class ItemType>
ItemType ArrayList<ItemType>::getEntry(const int& position) const throw(out_of_range){
  if(position <= itemCount) {
    return items[position-1];
  } else {
    throw out_of_range("There is no entry in the given position.");
  }
}

template<class ItemType>
bool ArrayList<ItemType>::insert(const int& position, const ItemType& newItem) {
  if(position > itemCount+1 || itemCount == MAX || position < 1) {
    return false;
  } else {
    for(int i=itemCount; i>=position; i--) {
      items[i] = items[i-1];
    }
    items[position-1] = newItem;
    itemCount++;
    return true;
  }
}

template<class ItemType>
bool ArrayList<ItemType>::remove(const int& position) {
  if(position > itemCount || position < 1) {
    return false;
  } else {
    for (int i=position; i<itemCount; i++) {
      items[i-1] = items[i];
    }
    itemCount--;
    return true;
  }
}

template<class ItemType>
bool ArrayList<ItemType>::replace(const int& position, const ItemType& newItem) {
  if (remove(position)) {
    insert(position, newItem);
    return true;
  } else {
    return false;
  }
}

template<class ItemType>
void ArrayList<ItemType>::displayEntry() const {
  for (int i=1; i <= itemCount; i++) {
    cout << getEntry(i) << " ";
  }
  if (itemCount == 0) {
    cout << "No Entries";
  }
  cout << endl;
}

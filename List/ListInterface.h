#ifndef _LIST_INTERFACE_H
#define _LIST_INTERFACE_H

template <class ItemType>
class ListInterface {
public:
  virtual bool isEmpty() const = 0;
  virtual int getItemCount() const = 0;
  virtual void reset() = 0;
  virtual ItemType getEntry(const int& position) const = 0;
  virtual bool insert(const int& position, const ItemType& newItem) = 0;
  virtual bool remove(const int& position) = 0;
  virtual bool replace(const int& position, const ItemType& newItem) = 0;
  virtual void displayEntry() const = 0;
};

#endif

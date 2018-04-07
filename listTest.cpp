#include<iostream>
#include<string>
#include "ArrayList.h"
#include "LinkList.h"

using namespace std;

int main() {
  // arrayList Test
  ArrayList<string>* arrayList = new ArrayList<string>;
  cout << "Is new array empty? " << arrayList->isEmpty() << endl;
  cout << "item count: " << arrayList->getItemCount() << endl;
  try {
    cout << arrayList->getEntry(1) << endl;
  }
  catch (out_of_range e) {
    cout << e.what() << endl;
  }
  string pool[5] = {"Hi", "This", "is", "test", "string"};
  for(int i=0; i<sizeof(pool)/sizeof(pool[0]); i++) {
    arrayList->insert(i+1, pool[i]);
  }
  for(int i=1; i<=arrayList->getItemCount(); i++) {
    cout << i << ". " << arrayList->getEntry(i) << endl;
  }
  arrayList->remove(2);
  cout << endl;
  for(int i=1; i<=arrayList->getItemCount(); i++) {
    cout << i << ". " << arrayList->getEntry(i) << endl;
  }
  arrayList->replace(3, "Replaced");
  cout << endl;
  for(int i=1; i<=arrayList->getItemCount(); i++) {
    cout << i << ". " << arrayList->getEntry(i) << endl;
  }
  cout << endl;

  // linkList Test
  LinkList<string>* linkList = new LinkList<string>;
  cout << "Is new link list empty? " << linkList->isEmpty() << endl;
  cout << "item count: " << linkList->getItemCount() << endl;
  try {
    cout << linkList->getEntry(1) << endl;
  }
  catch (out_of_range e) {
    cout << e.what() << endl;
  }
  for(int i = 0; i < sizeof(pool)/sizeof(pool[0]); i++) {
    linkList->insert(i+1, pool[i]);
  }
  for(int i = 1; i <= linkList->getItemCount(); i++) {
    cout << i << ". " << linkList->getEntry(i) << endl;
  }
  linkList->remove(4);
  cout << endl;
  for(int i = 1; i <= linkList->getItemCount(); i++) {
    cout << i << ". " << linkList->getEntry(i) << endl;
  }
  linkList->insert(4, "New");
  cout << endl;
  for(int i = 1; i <= linkList->getItemCount(); i++) {
    cout << i << ". " << linkList->getEntry(i) << endl;
  }
  linkList->replace(1, "Hello");
  cout << endl;
  for(int i = 1; i <= linkList->getItemCount(); i++) {
    cout << i << ". " << linkList->getEntry(i) << endl;
  }
  linkList->reset();
  cout << endl;
  for(int i = 1; i <= linkList->getItemCount(); i++) {
    cout << i << ". " << linkList->getEntry(i) << endl;
  }

  return 0;
}

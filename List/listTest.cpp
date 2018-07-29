#include<iostream>
#include<string>
#include "ArrayList.h"
#include "LinkedList.h"

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
  arrayList->displayEntry();
  arrayList->remove(2);
  arrayList->displayEntry();
  arrayList->replace(3, "Replaced");
  arrayList->displayEntry();

  // linkList Test
  LinkedList<string>* linkList = new LinkedList<string>;
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
  linkList->displayEntry();
  linkList->remove(4);
  linkList->displayEntry();
  linkList->insert(4, "New");
  linkList->displayEntry();
  linkList->replace(1, "Hello");
  linkList->displayEntry();
  linkList->reset();
  linkList->displayEntry();

  return 0;
}

#include <iostream>
#include <stdexcept>
#include "LinkedQueue.h"
#include "ArrayQueue.h"

using namespace std;

int main() {
  // Linked-based queue test driver
  LinkedQueue<int>* linkQ = new LinkedQueue<int>;
  cout << linkQ->isEmpty() << endl;
  linkQ->enqueue(5);
  linkQ->enqueue(3);
  linkQ->enqueue(7);
  linkQ->enqueue(2);
  cout << linkQ->isEmpty() << endl;
  while(!linkQ->isEmpty()) {
    cout << linkQ->peekFront() << " ";
    linkQ->dequeue();
  }
  cout << endl;

  // Array-based queue test driver
  ArrayQueue<int>* arrayQ = new ArrayQueue<int>;
  cout << arrayQ->isEmpty() << endl;
  arrayQ->enqueue(5);
  arrayQ->enqueue(3);
  arrayQ->enqueue(7);
  arrayQ->enqueue(2);
  cout << arrayQ->isEmpty() << endl;
  while(!arrayQ->isEmpty()) {
    cout << arrayQ->peekFront() << " ";
    arrayQ->dequeue();
  }
  cout << endl;
  return 0;
}

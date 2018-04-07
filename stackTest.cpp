#include<iostream>
#include<string>
#include "ArrayStack.h"
#include "LinkStack.h"

using namespace std;

int main() {
  // ArrayStack test
  ArrayStack<string> myStack = ArrayStack<string>();
  try {
    cout << myStack.peek() << endl;
  }
  catch(out_of_range e) {
    cout << "ERROR: " << e.what() << endl;
  }
  cout << "Is stack empty? " << myStack.isEmpty() << endl;
  myStack.push("First");
  myStack.push("Second");
  myStack.push("Third");
  while(!myStack.isEmpty()) {
    cout << myStack.peek() << endl;
    myStack.pop();
  }

  cout << endl << endl;

  LinkStack<string>* linkStack = new LinkStack<string>();
  try {
    cout << linkStack->peek() << endl;
  }
  catch (out_of_range e) {
    cout << e.what() << endl;
  }
  cout << "Is Stack Empty? " << linkStack->isEmpty() << endl;
  linkStack->push("First");
  linkStack->push("Second");
  linkStack->push("Third");
  while(!linkStack->isEmpty()) {
    cout << linkStack->peek() << endl;
    linkStack->pop();
  }

  return 0;
}

#include<string>
#include<iostream>
#include<iomanip>
// #include "ArrayList.h"
#include "LinkList.h"

using namespace std;

struct Product {
  string name;
  int price;
  int amount;
} product;

int main() {
  LinkList<Product>* list = new LinkList<Product>;
  int choice;
  bool quit = false;
  while(!quit) {
    cout << "*** Product Management ***" << endl << "1. Enter Products" << endl << "2. View Products" << endl << "3. Exit the Program" << endl;
    cin >> choice;
    cin.ignore();
    switch(choice) {
      case 1:
        while(choice==1) {
          cout << endl << "Enter the name: ";
          getline(cin, product.name);
          cout << "Enter the unit price: ";
          cin >> product.price;
          cout << "Enter the amount of product: ";
          cin >> product.amount;
          // cin.ignore();
          list->insert(1, product);
          cout << "Enter another product? (1 - yes. 2 - no) ";
          cin >> choice;
          cin.ignore();
        }
        cout << endl;
        break;
      case 2:
        cout << "----------------------------------------" << endl
             << "     Name     |  Unit Price  |  Amount  " << endl
             << "----------------------------------------" << endl;
        for(int i=1; i<=list->getItemCount(); i++) {
          product = list->getEntry(i);
          cout << setw(17) << left << product.name << "$ " << setw(14) << left << product.price << setw(10) << left << product.amount << endl;
        }
        cout << endl;
        break;
      case 3:
        quit = true;
        break;
      default:
        while(choice != 1 && choice != 2 && choice != 3) {
          cout << "Invalid Input." << endl;
          cin >> choice;
        }
    }
  }
  return 0;
}

#include<iostream>

using namespace std;

// template<class ItemType>
void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}
// template<class ItemType>
int partition(int* array, int first, int end) {
  int pivotIndex = first;
  int pivot = array[end];
  for(int i=pivotIndex; i < end; i++) {
    if(array[i] <= pivot) {
      swap(array[i], array[pivotIndex]);
      pivotIndex++;
    }
  }
  swap(array[pivotIndex], array[end]);
  return pivotIndex;
}

// template<class ItemType>
void quickSort(int* array, int first, int end) {
  if (first < end) {
    int pivotIndex = partition(array, first, end);

    quickSort(array, first, pivotIndex-1);
    quickSort(array, pivotIndex+1, end);
  }
}

int main() {
  int array[] = {3, 5, 4, 8, 9, 6, 1, 2, 7, 5, 3, 9, 2, 7, 6, 4};
  int length = sizeof(array)/sizeof(array[0]);
  for(int i=0; i < length; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
  quickSort(array, 0, length-1);
  for(int i=0; i < length; i++) {
    cout << array[i] << " ";
  }
  return 0;
}

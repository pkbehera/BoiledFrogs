#include <stdio.h>
#include <iostream>
using namespace std;

void swap(int data[], int i, int j) {
  int tmp = data[i];
  data[i] = data[j];
  data[j] = tmp;
}

//Notes:
//Heap definition:
//In an Array[a0, a1, a2, a3, ... , an]
//A[0] is the root element of the heap
//Left child of node n is A[2n + 1] and right child is A[2m + 2]

//Heap property:
//For max-heap key of a node is >= keys of its children
//For min-heap key of a node is <= keys of its children

//Node Number starts from 0
void heapify(int data[], int n, int len, bool asc) {
  int left = 2 * n + 1;
  int right = 2 * n + 2;
  if (left < len && ((asc && data[n] < data[left]) || data[n] > data[left])) {
    swap(data, n, left);
    heapify(data, left, len, asc);
  }
  if (right < len && ((asc && data[n] < data[right]) || data[n] > data[right])) {
    swap(data, n, right);
    heapify(data, right, len, asc);
  }
}

void createHeap(int data[], int len, bool asc) {
  //index starts with 0
  for (int i = len / 2 - 1; i >= 0; i--) {
    heapify(data, i, len, asc);
  }
}

void sort (int data[], int len, bool asc) {
  createHeap(data, len, asc);
  for (int i = 0; i < len; i++) {
    swap(data, 0, len - 1 - i);
    heapify(data, 0, len - 1 - i, asc);
  }
}

void print(int data[], int len) {
  for (int i = 0; i < len; i++) {
    cout << data[i] << " ";
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  int data[] = {9, 3, 5, 4, 6, 2, 1, 10, 7, 8, 20, 34, 22, 45, 12, 44, 13, 99, 14, 87};
  print(data, 20);
  sort(data, 20, false);
  print(data, 20);
  return 0;
}

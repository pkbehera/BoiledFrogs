#include <stdio.h>
#include <iostream>
using namespace std;

void swap(int data[], int i, int j) {
  int tmp = data[i];
  data[i] = data[j];
  data[j] = tmp;
}

void sort (int data[], int len, bool asc) {
  for (int i = 0; i < len - 1; i++) {
    for (int j = 0; j < len - 1 - i; j++) {
      if ((asc && data[j] > data[j + 1]) || data[j] < data[j + 1]) {
        swap(data, j, j + 1);
      }
    }
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

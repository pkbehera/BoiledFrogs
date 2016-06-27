#include <stdio.h>
#include <iostream>
using namespace std;

void sort (int data[], int len, bool asc) {
  for (int i = 0; i < len - 1; i++) {
    for (int j = 0; j < len - 1 - i; j++) {
      bool swap = false;
      if ((asc && data[j] > data[j + 1]) || data[j] < data[j + 1]) {
        int temp = data[j];
        data[j] = data[j + 1];
        data[j + 1] = temp;
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  int data[] = {9, 3, 5, 4, 6, 2, 1, 10, 7, 8, 20, 34, 22, 45, 12, 44, 13, 99, 14, 87};
  for (int i = 0; i < 20; i++) {
    cout << data[i] << " ";
  }
  cout << endl;
  sort(data, 20, false);
  for (int i = 0; i < 20; i++) {
    cout << data[i] << " ";
  }
  cout << endl;
  return 0;
}

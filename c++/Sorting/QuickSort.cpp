#include <stdio.h>
#include <iostream>
using namespace std;

void sort (int data[], int len, bool asc) {
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

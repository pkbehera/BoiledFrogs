#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/*Given an array of numbers, find the highest Product you can get from three
of these numbers. The input array will always have at least three integers.*/

int max(const int a, const int b) {
  return a > b ? a : b;
}

//Complexity: O(n)
int maxProduct(const int *data, const int len) {
  //Top 3
  int M1 = data[0];
  int I1 = 0;
  int M2 = data[1];
  int I2 = 1;
  int M3 = data[2];
  //Bottom 2
  int m1 = data[0];
  int i1 = 0;
  int m2 = data[1];
  for (int i = 0; i < len; i++) {
    if (data[i] > M1) {
      M3 = M2;
      M2 = M1;
      M1 = data[i];
      I2 = I1;
      I1 = i;
    } else if (data[i] > M2 && i != I1) {
      M3 = M2;
      M2 = data[i];
      I2 = i;
    } else if (data[i] > M3 && i != I1 && i != I2) {
      M3 = data[i];
    }

    if (data[i] < m1) {
      m2 = m1;
      m1 = data[i];
      i1 = i;
    } else if (data[i] < m2 && i != i1) {
      m2 = data[i];
    }
  }
  //cout << m1 << " " << m2 << " " << M3 << " " << M2 << " " << M1 << endl;
  return max(m1 * m2, M2 * M3) * M1;
}

int main(int argc, char const *argv[]) {
  cout << "Number of entries: ";
  int cnt;
  cin >> cnt;
  int* data = new int[cnt];
  for (int i = 0; i < cnt; i++) {
    cout << i << "th entry: ";
    cin >> data[i];
  }
  cout << "Max product: " << maxProduct(data, cnt) << endl;
  delete[] data;
  return 0;
}

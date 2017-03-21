#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
//Find the kth (k starts with 1) biggest number in the combination of 2 sorted array of integers
//The given arrays are sorted in ascending order
// a[1, 3, 5, 7], b[2, 4, 6, 8, 10]
// m = 4, n = 5, k = 7
// O(N) solution
int FindKthBiggest1(int *a, int m, int *b, int n, int k) {
  if (k > m + n || k < 1) {
    cout << "Error: Value of k can not be less than 1 or more than sum of m & n" << endl;
    exit(1);
  }
  int i, j, l = 1;
  int r;
  for (i = m - 1, j = n - 1; i >= 0 && j >= 0 && l <= k; l++) {
    r = a[i] > b[j] ? a[i--] : b[j--];
  }
  for (; i >= 0 && l <= k; l++) {
    r = a[i--];
  }
  for (; j >= 0 && l <= k; l++) {
    r = b[j--];
  }
  return r;
}

//O(logN)Solution - uses binary search
int FindKthBiggest(int *a, int m, int *b, int n, int k) {
  /*if (k > m + n || k < 1) {
    cout << "Error: Value of k can not be less than 1 or more than sum of m & n" << endl;
    exit(1);
  }*/
  if (n > m) { //ensure m > n
    return FindKthBiggest(b, n, a, m, k);
  }
  if (n == 0) {
    return a[m - k];
  }
  if (k == 1) {
    return a[m - 1] > b[n - 1] ? a[m - 1] : b[n - 1];
  }
  if (k == m + n) {
    return a[0] > b[0] ? a[0] : b[0];
  }

  int i = k / 2 < m ? k / 2 : m;
  int j = k / 2 < n ? k / 2 : n;
  if (a[m - i] < b[m - j]) {
    return FindKthBiggest(a + i, m - i, b, j, k - i);
  } else {
    return FindKthBiggest(a, i, b + j, m - j, k - j);
  }
}

int main(int argc, char const *argv[]) {
  int a[] = { 1, 3, 5, 7 };
  int b[] = { 2, 4, 6, 8, 10 };
  // m = 4, n = 5, k = 7
  for (int i = 1; i < 10; i++) {
    cout << FindKthBiggest(a, 4, b, 5, i) << endl;
  }
  return 0;
}

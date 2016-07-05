#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/*Write a function to print merged, sorted list from 2 already sorted arrays
int arr1[] = {3, 4, 6, 10, 11, 15};
int arr2[] = {1, 5, 8, 12, 14, 19};

merge(arr1, 6, arr2, 6);
// prints 1, 3, 4, 5, 6, 8, 10, 11, 12, 14, 15, 19
*/
void merge(int sorted1[], int len1, int sorted2[], int len2) {
  int i = 0;
  int j = 0;
  //Two finger Algorithm
  while (i < len1 && j < len2) {
    if (sorted1[i] < sorted2[j]) {
      cout << sorted1[i++] << " ";
    } else {
      cout << sorted2[j++] << " ";
    }
  }
  //Only one of these loops will be executed
  //because eiter i == l or j == r when the control reaches here
  while (i < len1) {
    cout << sorted1[i++] << " ";
  }
  while (j < len2) {
    cout << sorted2[j++] << " ";
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  int a[] = {3, 4, 6, 10, 11, 15};
  int b[] = {1, 5, 8, 12, 14, 19};
  merge(a, 6, b, 6);
  return 0;
}

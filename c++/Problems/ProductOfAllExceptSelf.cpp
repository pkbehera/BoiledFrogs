#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/*
With an array of numbers, for each index find the product of all integer except
the number at that index. Write a function that takes an array of numbers &
returns an array of such products.

e.g., given:
  [1, 7, 3, 4]
the function would return:
  [84, 12, 28, 21]
by calculating:
  [7*3*4, 1*3*4, 1*7*4, 1*7*3]
Do not use division in your solution.
*/

//Complexity: O(n)
//Two for loops, one in forward direction and one in backward
int* product(const int *data, const int len) {
  int* temp = new int[len];
  int prodSofar = 1;
  for (int i = 0; i < len; i++) {
    temp[i] = prodSofar;
    prodSofar *= data[i];
  }
  prodSofar = 1;
  for (int i = len - 1; i >= 0; i--) {
    temp[i] *= prodSofar;
    prodSofar *= data[i];
  }
  return temp;
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
  int* out = product(data, cnt);
  cout << "Outout:";
  for (int i = 0; i < cnt; i++) {
    cout << " " << out[i];
  }
  cout << endl;
  delete[] out;
  delete[] data;
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define LEN 99
//In an array 1-100 numbers are stored, only one number is missing. Find it.
int missingNum(int data[], int len = LEN) {
  int xr = 1;
  for (int i = 2; i < len + 2; i++) {
    xr ^= i;
  }
  for (int i = 0; i < len; i++) {
    xr ^= data[i];
  }
  return xr;
}

int missingNum1(int data[], int len = LEN) {
  long sum = (len + 1) * (len + 2) / 2;
  for (int i = 0; i < len; i++) {
    sum -= data[i];
  }
  return sum;
}

//In an array 1-100 numbers are stored, only one number is duplicate. Find it.
int dupNumber(int data[], int len = LEN + 2) {
  int xr = 1;
  for (int i = 2; i < len; i++) {
    xr ^= i;
  }
  for (int i = 0; i < len; i++) {
    xr ^= data[i];
  }
  return xr;
}

int dupNumber1(int data[], int len = LEN + 2) {
  long sum = 0 - (len - 1) * len / 2;
  for (int i = 0; i < len; i++) {
    sum += data[i];
  }
  return sum;
}

int main(int argc, char const *argv[]) {
  int data[LEN];
  srand (time(NULL));
  int rnd = rand() % (LEN + 1) + 1;
  cout << rnd << endl;
  int n = 1;
  for (int i = 0; i < LEN; i++) {
    if (n != rnd) {
      data[i] = n++;
    } else {
      n++;
      data[i] = n++;
    }
    cout << data[i] << " ";
  }
  cout << endl;
  cout << "Missing: " << missingNum(data) << endl;
  cout << "Missing1: " << missingNum1(data) << endl;
  int data1[LEN + 2];
  n = 1;
  for (int i = 0; i < LEN + 2; i++) {
    if (n != rnd) {
      data1[i] = n++;
    } else {
      data1[i++] = n;
      data1[i] = n++;
      cout << data1[i-1] << " ";
    }
    cout << data1[i] << " ";
  }
  cout << endl;
  cout << "Duplicate: " << dupNumber(data1) << endl;
  cout << "Duplicate1: " << dupNumber1(data1) << endl;
  return 0;
}

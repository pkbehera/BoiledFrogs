#include <stdio.h>
#include <iostream>
using namespace std;

int func1(int *a, int b) {
  int xx = 0;
  for (int i = 0; i < b; i++) {
    xx += *a++;
  }
  return xx;
}

int func2(int* pp, int b, int c) {
  int x = 0;
  for (int j = 0; j < b; j++) {
    for (int i = 0; i < c; i++) {
      x += *(pp + j*c + i);
    }
  }
  return x;
}

class A {
public:
    A() {}
    ~A() {
        throw 42;
    }
};

bool pow(int x) {
}

int main1(int argc, char const *argv[]) {
  //A: what will be the output here?
  cout << 25u - 50 << endl;
  //int data[] = {9, 3, 5, 4, 6, 2, 1, 10};
  //cout << func1(data, 8) << endl;
  int* pp;
  int aa[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  pp = *aa;
  //B: What is happening here?
  cout << func2(pp, 4, 3) << endl;

  //C: anything wrong here?
  size_t sz = sizeof(int);
  while ( --sz >= 0 ) {
    /* do something */
  }

  //D: What is the output here?
  int a[] = {1, 2, 3, 4, 5, 6};
  cout << (1 + 3)[a] - a[0] + (a + 1)[2];

  //E: What happens here?
  try {
    A a;
    throw 32;
  } catch(int a) {
    cout << a;
  }

  //F: Virtual inheritance? what and when to use?
  //G: Difference between a class and and struct?
  //H: Implement a void function F that takes pointers to two arrays of integers (A and B)
  //and a size N as parameters. It then populates B where B[i] is the product of all A[j]
  //where j != i.
  //For example: if A = {2, 1, 5, 9}, then B would be {45, 90, 18, 10}

  //I: Volatile keyword? Mutable?
  //pointers vs references
  //function pointers
  //write a function to reverse name: first_name last_name -> last_name first_name

  //Check if a binary tree is a BST or not?
  return 0;
}

//Given an array, return a new array with exactly 2 elements:
//the first & last elements of the given array.
int* boundary(int* nums, int n)
{
    int *a = new int[2];//must allocate memory dynamically
    a[0] = nums[0];
    a[1] = nums[n-1];
    return a;
}

void F(int* A, int* B, int N) {
  int m = 1;
  int zeros = 0;
  int zeroInd= -1;

  for (int i = 0; i < N; ++i) {
    B[i] = 0;
    if (A[i] == 0) {
      ++zeros;
      zeroInd = i;
    } else {
      m *= A[i];
    }
  }

  if (zeros == 0) {
    for (int i = 0; i < N; ++i) {
      B[i] = m / A[i];
    }
    return;
  }

  if (zeros >= 2) {
      return;
  }
  B[zeroInd] = m;
}

void reverse(char *begin, char *end) {
  while (begin < end) {
    char *temp = begin;
    *begin++ = *end;
    *end-- = *temp;
  }
}

void revWords(char* s) {
  char *temp = s;
  char *wbegin = NULL;
  while (*temp) {
    if (wbegin == NULL && *temp != ' ') {
      wbegin = temp;
    }
    if (wbegin && (*(temp+1) == ' ' || *(temp+1) == '\0')) {
      reverse(wbegin, temp);
      wbegin = NULL;
    }
    temp++;
  }
  reverse(s, temp-1);
}

bool powof2(int x) {
  double t = x >> 1;
  if (t == (double)x / 2) {
    return true;
  }
  return false;
}

int main(int argc, char const *argv[]) {
  cout << powof2(1) << endl;
  cout << powof2(2) << endl;
  cout << powof2(4) << endl;
  cout << powof2(8) << endl;
  cout << powof2(16) << endl;
  cout << powof2(3) << endl;
  cout << powof2(5) << endl;
  cout << powof2(6) << endl;
  cout << powof2(7) << endl;
}

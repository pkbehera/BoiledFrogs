#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

void check(int n) {
  if (n < 1) {
    cout << "n should be greater than 0" << endl;
    exit(-1);
  }
}
//Fibonacci number using recursion
int fib_r(int n) {
  check(n);
  int f1 = 0;
  int f2 = 1;
  if (n == 1) {
    return f1;
  }
  if (n == 2) {
    return f2;
  }
  return fib_r(n - 1) + fib_r(n - 2);
}

//Fibonacci number using dynamic programming
int fib_d(int n) {
  check(n);
  int f1 = 0;
  int f2 = 1;
  if (n == 1) {
    return f1;
  }
  if (n == 2) {
    return f2;
  }
  for (int i = 3; i <= n; i++) {
    int temp = f2;
    f2 += f1;
    f1 = temp;
  }
  return f2;
}

int main(int argc, char const *argv[]) {
  int w = 10;
  cout << setw(w) << left << "I" << setw(w) << right << "fib_r" << setw(w) << right << "fib_d" << endl;
  for (int i = 1; i <= 20; i++) {
    cout << setw(w) << left << i << setw(w) << right << fib_r(i) << setw(w) << right << fib_d(i) << endl;
  }
  return 0;
}

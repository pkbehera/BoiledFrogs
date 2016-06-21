#include "Stack-linked-list.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

void printMove(char f, char t, int disk) {
  cout << "Move disk " << disk << " from " << f << " to " << t << endl;
}

void move(Stack *src, Stack *des, char s, char d) {
  int srcDisk = src->pop();
  int desDisk = des->pop();
  if (srcDisk == INT_MIN) {
    src->push(desDisk);
    printMove(d, s, desDisk);
  } else if (desDisk == INT_MIN) {
    des->push(srcDisk);
    printMove(s, d, srcDisk);
  } else if (srcDisk > desDisk) {
    src->push(srcDisk);
    src->push(desDisk);
    printMove(d, s, desDisk);
  } else {
    des->push(desDisk);
    des->push(srcDisk);
    printMove(s, d, srcDisk);
  }
}

void tohi(int n) {
  if (n < 1) {
    std::cout << "Number of disks should be 1 or more." << std::endl;
    return;
  }
  Stack *src = new Stack();
  Stack *des = new Stack();
  Stack *aux = new Stack();
  char s = 'S';
  char d = 'D';
  char a = 'A';

  if (n % 2 == 0) {
    d = 'A';
    a = 'D';
  }

  for (int i = n; i > 0; i--) {
    src->push(i);
  }

  for (int i = 1; i <= pow(2, n) - 1; i++) {
    cout << "Step # " << i << ": ";
    switch (i % 3) {
      case 0:
        move(aux, des, a, d);
        break;
      case 1:
        move(src, des, s, d);
        break;
      case 2:
        move(src, aux, s, a);
        break;
    }
  }
  delete src;
  src = NULL;
  delete des;
  des = NULL;
  delete aux;
  aux = NULL;
}

int main(int argc, char const *argv[]) {
  cout << "Number of disks: ";
  int n;
  cin >> n;
  tohi(n);
  return 0;
}

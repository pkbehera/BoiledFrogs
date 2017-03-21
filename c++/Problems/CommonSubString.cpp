#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

class Node {
  char _c;
  Node* _n1;
  Node* _n2;

public:
  Node(char c) {
    _n1 = NULL;
    _n2 = NULL;
  };
  void n1(Node* n) { _n1 = n; };
  void n2(Node* n) { _n2 = n; };
  Node* n1() { return _n1; };
  Node* n2() { return _n2; };
  char c() { return _c; };
};

void create(string &s1, string &s2, Node* h1, Node* h2) {
  h1 = NULL;
  Node* p = NULL;
  for (char c : s1) {
    cout << c;
    Node *n = new Node(c);
    if (p != NULL) {
      p->n1(n);
    }
    p = n;
    if (h1 == NULL) {
      h1 = p;
    }
  }
}

void print(Node* h) {
  Node* p = h;
  while (p != NULL) {
    cout << p->c();
    p = p->n1();
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  Node *h1, *h2;
  create(s1, s2, h1, h2);
  print(h1);
  return 0;
}

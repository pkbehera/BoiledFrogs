#include <stdio.h>
#include <iostream>
using namespace std;

void print(int data[], int len) {
  for (int i = 0; i < len; i++) {
    cout << data[i] << " ";
  }
  cout << endl;
}

class Node {
  int _val;
  Node* _parent;
  Node* _left;
  Node* _right;

public:
  Node(int val);
  void parent(Node *p) { _parent = p; };
  void left(Node *l) { _left = l; };
  void right(Node *r) { _right = r; };
  void append(Node* n);
  void inOrder();
  //void preOrder();
  //void postOrder();
  int val() { return _val; };
  Node* parent() { return _parent; };
  Node* left() { return _left; };
  Node* right() { return _right; };
  Node* root();
};

Node::Node(int v) {
  _val = v;
  _parent = NULL;
  _left = NULL;
  _right = NULL;
}

Node* Node::root() {
  Node* n = this;
  while (true) {
    Node* p = n->parent();
    if (p == NULL) {
      return n;
    }
    n = p;
  }
}

void Node::inOrder(){
  //Traverse left side first
  if (left() != NULL) {
    left()->inOrder();
  }
  //Then Traverse self
  cout << val() << " ";
  //Then the right side
  if (right() != NULL) {
    right()->inOrder();
  }
}

/*void Node::postOrder() {
  if (right() != NULL) {
    right()->inOrder();
  }
  cout << val() << " ";
  if (left() != NULL) {
    left()->inOrder();
  }
}*/

void Node::append(Node* n) {
  bool goLeft = n->val() < val();
  Node *next = goLeft ? left() : right();
  if (next == NULL) {
    n->parent(this);
    goLeft ? left(n) : right(n);
  } else {
    next->append(n);
  }
}

Node* createBST(int data[], int len) {
  Node *root = new Node(data[0]);
  for (int i = 1; i < len; i++) {
    Node* n = new Node(data[i]);
    root->append(n);
  }
  return root;
}

void sort(int data[], int len) {
  Node* bst = createBST(data, 20);
  bst->inOrder();
  cout << endl;
}

int main(int argc, char const *argv[]) {
  int data[] = {9, 3, 5, 4, 6, 2, 1, 10, 7, 8, 20, 34, 22, 45, 12, 44, 13, 99, 14, 87};
  print(data, 20);
  sort(data, 20);
  return 0;
}

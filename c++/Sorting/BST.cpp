#include <stdio.h>
#include <assert.h>
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
  int _sz; //size of the subtree under this node
  int _h; //Height of the subtree under this node
  Node* _parent;
  Node* _left;
  Node* _right;
  void parent(Node *p);
  void left(Node *l);
  void right(Node *r);
  void updateSize();
  void updateHeight();
  Node* root();
  Node* find(int i);

public:
  Node(int val);
  void insert(Node* n);
  void remove(int n);
  void preOrder();
  void inOrder();
  void inOrderRfirst();
  void postOrder();
  void levelOrder();

  int size() { return _sz; };
  int height() { return _h; };
  int min();
  int max();
  int predecessor();
  int successor();
  bool isBST();
};

int Node::predecessor() {
  return 0;
}

int Node::successor() {
  return 0;
}

bool Node::isBST() {
  if (_left != NULL && (_left->_val > _val || !_left->isBST())) {
    return false;
  }
  if (_right != NULL && (_right->_val < _val || !_right->isBST())) {
    return false;
  }
  return true;
}

Node::Node(int v) {
  _val = v;
  _sz = 1;
  _h = 1;
  _parent = NULL;
  _left = NULL;
  _right = NULL;
}

Node* Node::root() {
  Node* n = this;
  while (true) {
    Node* p = n->_parent;
    if (p == NULL) {
      return n;
    }
    n = p;
  }
}

void Node::parent(Node *p) {
  _parent = p;
}

void Node::left(Node *l) {
  _left = l;
  if(l != NULL) {
    l->parent(this);
  }
  updateSize();
  updateHeight();
}

void Node::right(Node *r) {
  _right = r;
  if(r !=NULL) {
    r->parent(this);
  }
  updateSize();
  updateHeight();
}

void Node::updateSize() {
  _sz = 1;
  if (_right != NULL) {
    _sz += _right->size();
  }
  if (_left != NULL) {
    _sz += _left->size();
  }
  if(_parent != NULL) {
    _parent->updateSize();
  }
}

void Node::updateHeight() {
  int lsz = _left == NULL ? -1 : _left->height();
  int rsz = _right == NULL ? -1 : _right->height();
  _h = (lsz > rsz ? lsz : rsz) + 1;
  if(_parent != NULL) {
    _parent->updateHeight();
  }
}

int Node::min() {
  Node* n = this;
  while (true) {
    Node* l = n->_left;
    if (l == NULL) {
      return n->_val;
    }
    n = l;
  }
}

int Node::max() {
  Node* n = this;
  while (true) {
    Node* r = n->_right;
    if (r == NULL) {
      return n->_val;
    }
    n = r;
  }
}

void Node::preOrder() {
  cout << _val << " ";
  if (_left != NULL) {
    _left->preOrder();
  }
  if (_right != NULL) {
    _right->preOrder();
  }
}

void Node::inOrder() {
  //Traverse left side first
  if (_left != NULL) {
    _left->inOrder();
  }
  //Then Traverse self
  cout << _val << " ";
  //Then the right side
  if (_right != NULL) {
    _right->inOrder();
  }
}

void Node::inOrderRfirst() {
  if (_right != NULL) {
    _right->inOrderRfirst();
  }
  cout << _val << " ";
  if (_left != NULL) {
    _left->inOrderRfirst();
  }
}

void Node::postOrder() {
  //Traverse left side first
  if (_left != NULL) {
    _left->postOrder();
  }
  //Then the right side
  if (_right != NULL) {
    _right->postOrder();
  }
  //Then Traverse self
  cout << _val << " ";
}

void Node::levelOrder() {
  //???
}

void Node::insert(Node* n) {
  bool goLeft = n->_val < _val;
  Node *next = goLeft ? _left : _right;
  if (next == NULL) {
    goLeft ? left(n) : right(n);
  } else {
    next->insert(n);
  }
}

Node* Node::find(int n) {
    if (n == _val) {
      return this;
    }
    if (n > _val) {
      return _right->find(n);
    }
    if (n < _val) {
      return _left->find(n);
    }
    return NULL;
}

void Node::remove(int i) {
  Node* n = find(i);
  if (n != NULL) {
    Node* l = n->_left;
    Node* r = n->_right;
    Node* p = n->_parent;
    if (p != NULL) {
      if (p->_left == n) {
          p->left(l != NULL ? l : r);
      } else {
          p->right(l != NULL ? l : r);
      }
    }
    if (l != NULL) {
      l->right(r);
    }
    n->parent(NULL);
    n->left(NULL);
    n->right(NULL);
  }
}

Node* createBST(int data[], int len) {
  Node *root = new Node(data[0]);
  for (int i = 1; i < len; i++) {
    Node* n = new Node(data[i]);
    root->insert(n);
  }
  return root;
}

void sort(int data[], int len, bool asc) {
  Node* bst = createBST(data, 20);
  cout << "PreOrder: ";
  bst->preOrder();
  cout << endl;
  cout << "PostOrder: ";
  bst->postOrder();
  cout << endl;

  cout << "IsBST: " << boolalpha << bst->isBST() << endl;
  cout << "Size: " << bst->size() << endl;
  cout << "Height: " << bst->height() << endl;
  cout << "Min: " << bst->min() << endl;
  cout << "Max: " << bst->max() << endl;
  cout << "InOrder (Sorting): ";
  asc ? bst->inOrder() : bst->inOrderRfirst();
  cout << endl;

  bst->remove(10);
  cout << "After removing node with valye 10: " << endl;
  cout << "IsBST: " << boolalpha << bst->isBST() << endl;
  cout << "Size: " << bst->size() << endl;
  cout << "Height: " << bst->height() << endl;
  cout << "Min: " << bst->min() << endl;
  cout << "Max: " << bst->max() << endl;
  cout << "InOrder (Sorting): ";
  asc ? bst->inOrder() : bst->inOrderRfirst();
  cout << endl;
}

int main(int argc, char const *argv[]) {
  int data[] = {9, 3, 5, 4, 6, 2, 1, 10, 7, 8, 20, 34, 22, 45, 12, 44, 13, 99, 14, 87};
  cout << "Input: ";
  print(data, 20);
  sort(data, 20, false);
  return 0;
}

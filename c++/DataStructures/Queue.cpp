#include "Queue.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

QueueNode::QueueNode(int i) {
  _data = i;
  _next = NULL;
}

void QueueNode::setNext(QueueNode* n) {
  _next = n;
}

int QueueNode::data() {
  return _data;
}

QueueNode* QueueNode::next() {
  return _next;
}

Queue::Queue() {
  head = NULL;
  tail = NULL;
}

bool Queue::isEmpty() {
  return head == NULL;
}

int Queue::getFront() {
  if (isEmpty()) {
    return INT_MIN;
  }
  return head->data();
}

int Queue::dequeue() {
  if (isEmpty()) {
    return INT_MIN;
  }
  QueueNode *n = head;
  int i = n->data();
  head = head->next();
  if (head == NULL) {
    tail = NULL;
  }
  delete n;
  return i;
}

void Queue::enqueue(int i) {
  QueueNode *n = new QueueNode(i);
  if (tail != NULL) {
    tail->setNext(n);
  }
  tail = n;
  if (head == NULL) {
    head = n;
  }
}

void Queue::clear() {
  while (!isEmpty()) {
    dequeue();
  }
}

Queue::~Queue() {
  clear();
}

int main(int argc, char const *argv[]) {
  Queue *q = new Queue();
  for (int i = 1; i <= 10; i++) {
    q->enqueue(i);
  }
  cout << "Front: " << q->getFront() << endl;
  cout << "Dequeue: ";
  for (int i = 1; i <= 10; i++) {
    cout << q->dequeue() << " ";
  }
  cout << endl;
  return 0;
}

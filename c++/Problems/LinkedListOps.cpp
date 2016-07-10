#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Node {
public:
  int data;
  Node* next;
};

void printList(Node* const head) {
  Node* temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

Node* createList(const int data[], const size_t len) {
  Node* temp = NULL;
  Node* head = NULL;
  for (size_t i = 0; i < len; i++) {
    Node* node = new Node();
    node->data = data[i];
    node->next = NULL;
    if (head == NULL) {
      head = node;
    }
    if (temp != NULL) {
      temp->next = node;
    }
    temp = node;
  }
  return head;
}

Node* reverseList(Node* const head) {
  Node* node = head;
  Node* prev = NULL;
  while (node != NULL) {
    Node* temp = node->next;
    node->next = prev;
    prev = node;
    node = temp;
  }
  return prev;
}

bool cyclic(Node* const head) {
  Node* slow = head;
  Node* fast = head;
  while (slow != NULL && fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      return true;
    }
  }
  return false;
}

//To delete a given node in O(1) time, copy the next node's data & next pointer
//to the given node and then free the next node
//Demerits -
//Does not work for the last node
//The given pointer is not freed but the next pointer which could lead to issues
void deleteNode(Node* n) {
  if (n->next != NULL) {
    Node* temp = n->next;
    n->data = temp->data;
    n->next = temp->next;
    delete(temp);
  } else {
    cout << "Can not delete last node, without previous pointer!" << endl;
  }
}

int main(int argc, char const *argv[]) {
  int data[] = {1, 2, 3, 4, 5};
  Node* list = createList(data, 5);
  printList(list);
  Node* rlist = reverseList(list);
  printList(rlist);
  cout << "Cyclic: " << boolalpha << cyclic(rlist) << endl;
  return 0;
}

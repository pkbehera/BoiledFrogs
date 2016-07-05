/*
Question: Write a function (in C# or C++) to merge two already sorted linked
lists, do not use recursion. Given a data structure:

class Node {
public:
  int data;
  Node* next;
};

Implement function:
Node* Merge (Node* head1, Node* head2){…}

It takes in two already sorted linked lists (in ascendant order, duplicates allowed)
and is supposed to merge them into a single sorted linked list (in ascendant order,
duplicates allowed) and returns the new head
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Node {
public:
  int data;
  Node* next;
};

Node* createNode(int data) {
  Node* node = new Node();
  node->next = NULL;
  node->data = data;
  return node;
}

void setCurHead(Node* &head, Node* &curr, Node* const node) {
  if (head == NULL) {
    head = node;
  }
  if (curr != NULL) {
    curr->next = node;
  }
  curr = node;
}

//Complexity: O(n) where n is sum of the number of nodes in the given lists
//Input:
//head1 = head of first sorted lnked list
//head2 = head of second sorted linked list
//Returns head of a new, merged & sorted link list
//The input linked lists are not modified in any way
Node* Merge (Node* const head1, Node* const head2) {
  Node* node1 = head1;
  Node* node2 = head2;
  Node* head = NULL;
  Node* curr = NULL;
  while (node1 != NULL && node2 != NULL) {
    Node* node;
    if (node1->data < node2->data) {
      //node = node1; //If we want to reuse the input lists
      node = createNode(node1->data);
      node1 = node1->next;
    } else {
      //node = node2;
      node = createNode(node2->data);
      node2 = node2->next;
    }
    setCurHead(head, curr, node);
  }

  //Append the remaining nodes
  while (node1 != NULL) {
    //node = node1;
    Node* node = createNode(node1->data);
    node1 = node1->next;
    setCurHead(head, curr, node);
  }
  while (node2 != NULL) {
    //node = node2;
    Node* node = createNode(node2->data);
    node2 = node2->next;
    setCurHead(head, curr, node);
  }
  return head;
}

//Test code to create a linked list from a given array
Node* createList(const int* const data, const int len) {
  Node* head = NULL;
  Node* curr = NULL;
  for (int i = 0; i < len; i++) {
    Node* n = createNode(data[i]);
    if (head == NULL) {
      head = n;
    }
    if (curr != NULL) {
      curr->next = n;
      curr = curr->next;
    } else {
      curr = n;
    }
  }
  return head;
}

//utility method to print a linked list
void printList(Node* const head) {
  Node* curr = head;
  while (curr != NULL) {
    cout << curr->data << " ";
    curr = curr->next;
  }
  cout << endl;
}

//Notes: Compiled and tested with g++
//Test code
int main(int argc, char const *argv[]) {
  int arr1[] = {3, 4, 6, 8, 10, 11, 15, 19};
  int arr2[] = {1, 5, 8, 12, 14, 19};
  Node* head1 = createList(arr1, 8);
  Node* head2 = createList(arr2, 6);
  printList(head1);
  printList(head2);
  Node* head3 = Merge(head1, head2);
  printList(head3);
  return 0;
}

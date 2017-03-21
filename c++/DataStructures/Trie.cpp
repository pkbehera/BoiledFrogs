#include "Trie.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int TrieNode::_numNodes = 0;

TrieNode::TrieNode(char c) {
  _c = c;
  _nxtCnt = 0;
  //_next = TrieNode*[MAX];
  for (int i = 0; i < MAX; i++) {
    _next[i] = NULL;
  }
  _numNodes++;
}

TrieNode::~TrieNode() {
}

char TrieNode::c() {
  return _c;
}

void TrieNode::addNext(TrieNode* node) {
  _next[_nxtCnt++] = node;
}

int TrieNode::nextCount() {
  return _nxtCnt;
}

Trie::Trie() {
  head = NULL;
}

Trie::~Trie() {
  //TODO: Delete all nodes
}

TrieNode* Trie::getNode(char c) {
  TrieNode* n = NULL;
  if (head != NULL) {
    n = head;
    while (n->c() != c) {

      for (int i = 0; i < MAX; i++) {

      }
    }
  } else {
    n = new TrieNode(c);
    head = n;
  }
  return n;
}

void Trie::addString(const char* str) {

}

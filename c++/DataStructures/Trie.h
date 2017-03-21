const int MAX = 10;

class TrieNode {
  static int _numNodes;
  char _c;
  int _nxtCnt;
  TrieNode* _next[MAX];
public:
  TrieNode(char c);
  ~TrieNode();
  char c();
  int nextCount();
  void addNext(TrieNode *node);
  TrieNode* getNext(char c);
};

class Trie {
  TrieNode *head;
public:
  Trie();
  ~Trie();
  TrieNode* getNode(char c);
  void addString(const char* str);
};

class QueueNode {
  int _data;
  QueueNode* _next;
public:
  int data();
  QueueNode* next();
  void setNext(QueueNode* n);
  QueueNode(int i);
};

class Queue {
  QueueNode* head;
  QueueNode* tail;
public:
  Queue();
  ~Queue();
  bool isEmpty();
  int getFront();
  int dequeue();
  void enqueue(int i);
  void clear();
};

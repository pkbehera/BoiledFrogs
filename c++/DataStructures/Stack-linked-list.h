class StackNode {
	StackNode* _next;
	int _data;
public:
	StackNode(const int i);
	~StackNode();
	void setNext(StackNode* node);
	int data();
	StackNode* next();
};

class Stack {
	StackNode* top;
public:
	Stack();
	~Stack();
	void push(const int i);
	int pop();
	int peek();
	bool isEmpty();
};

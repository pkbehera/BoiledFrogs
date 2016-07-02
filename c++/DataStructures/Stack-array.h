/*A Stack data structure having a fixed capacity*/
class Stack {
	unsigned capacity;
	int topInd; //Index of the top most item, in array
	int *array;
public:
	Stack(const int capacity);
	~Stack();
	int pop();
	void push(const int i);
	int peek();
	bool isFull();
	bool isEmpty();
};

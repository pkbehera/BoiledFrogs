#include "Stack-linked-list.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

StackNode::StackNode(const int i) {
	_next = NULL;
	_data = i;
}

StackNode::~StackNode() {
	_next = NULL;
}

void StackNode::setNext(StackNode *node) {
	_next = node;
}

int StackNode::data() {
	return _data;
}

StackNode* StackNode::next() {
	return _next;
}

Stack::Stack() {
	top = NULL;
}

Stack::~Stack() {
	while (!isEmpty()) {
		StackNode *node = top;
		top = top->next();
		delete node;
	}
}

void Stack::push(const int i) {
	StackNode *node = new StackNode(i);
	node->setNext(top);
	top = node;
}

int Stack::peek() {
	if (isEmpty()) {
		return INT_MIN;
	}
	return top->data();
}

int Stack::pop() {
	if (isEmpty()) {
		return INT_MIN;
	}
	StackNode *node = top;
	int ret = node->data();
	top = top->next();
	delete node;
	return ret;
}

bool Stack::isEmpty() {
	return top == NULL;
}

int main(int argc, char** argv) {
	Stack st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	std::cout << "Peek " << st.peek() << std::endl;
	std::cout << "Pop " << st.pop() << std::endl;
	std::cout << "Pop " << st.pop() << std::endl;
	std::cout << "Pop " << st.pop() << std::endl;
}

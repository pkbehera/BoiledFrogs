#include "Stack-array.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

Stack::Stack(int capacity) {
	this->capacity = capacity;
	array = new int[capacity];
	topInd = -1;
}

Stack::~Stack() {
	delete[] array;
}

void Stack::push(const int i) {
	if (!isFull()) {
		array[++topInd] = i;
		cout << "Pushed " << i << " in the stack" << endl;
	} else {
		cout << "This stack is already full..." << endl;
	}
}

int Stack::pop() {
	if (!isEmpty()) {
		int i = array[topInd--];
		return i;
	} else {
		return INT_MIN;
	}
}

int Stack::peek() {
	if (!isEmpty()) {
		int i = array[topInd];
		return i;
	} else {
		return INT_MIN;
	}
}

bool Stack::isFull() {
	return topInd == capacity - 1;
}

bool Stack::isEmpty() {
	return topInd == -1;
}

int main(int argc, char** argv) {
	Stack *st = new Stack(10);
	st->push(10);
	st->push(20);
	st->push(30);
	st->push(40);
	st->push(50);
        cout << "isEmpty(): " << st->isEmpty() << endl;
        cout << "isFull(): " << st->isFull() << endl;
        cout << "peek(): " << st->peek() << endl;
	cout << "Popping all... " << endl;
	while (!st->isEmpty()) {
		cout << st->pop() << endl;
	}
	return 0;
}

#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

template<class T>
class myStack : public Stack<T> {
public:
	myStack(int s) : Stack<T>(s) {}

	void push(T value) override {
		if (!isFull()) {
			Stack<T>::stack[Stack<T>::currentSize] = value;
			Stack<T>::currentSize++;
		}
		else {
			cout << "Stack is full. Cannot push " << value << endl;
		}
	}

	T pop() override {
		if (!isEmpty()) {
			Stack<T>::currentSize--;
			return Stack<T>::stack[Stack<T>::currentSize];
		}
		cout<<"Pop from an empty stack";
	}

	T top() const override {
		if (!isEmpty()) {
			return Stack<T>::stack[Stack<T>::currentSize - 1];
		}
		cout<<"Peek from an empty stack";
	}

	bool isEmpty() const override {
		return Stack<T>::currentSize == 0;
	}

	bool isFull() const override {
		return Stack<T>::currentSize == Stack<T>::maxSize;
	}

	void display() const override {  
		cout << "Max size of stack is " << Stack<T>::maxSize << endl;
		cout << "Current size of stack is " << Stack<T>::currentSize << endl;
		cout << "Elements in the stack (top to bottom):" << endl;
		for (int i = Stack<T>::currentSize - 1; i >= 0; i--) {
			cout << Stack<T>::stack[i] << endl;
		}
	}
};

template<class T>
myStack<T> reverseStack(myStack<T>& originalStack) {
	myStack<T> reversedStack(originalStack.getmaxSize());
	myStack<T> tempStack(originalStack.getmaxSize());

	while (!originalStack.isEmpty()) {
		tempStack.push(originalStack.pop());
	}
	while (!tempStack.isEmpty()) {
		reversedStack.push(tempStack.pop());
	}

	return reversedStack;
}

#endif 

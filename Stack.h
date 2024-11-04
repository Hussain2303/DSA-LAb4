#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <class T>
class Stack {
protected:
	T* stack;
	int currentSize;
	int maxSize;
public:
	Stack(int s);  // Constructor
	virtual void push(T value) = 0; // Pure virtual functions
	virtual T pop() = 0;
	virtual T top() const = 0;
	virtual bool isEmpty() const = 0;
	virtual bool isFull() const = 0;
	virtual void display() const = 0; // Marked as const
	virtual ~Stack();  // Virtual destructor
	int getmaxSize() const; // Added const
};

// Constructor definition
template <class T>
Stack<T>::Stack(int s) {
	stack = new T[s];
	maxSize = s;
	currentSize = 0;
}

template <class T>
Stack<T>::~Stack() {
	delete[] stack;
	stack = nullptr;
}

// Getter for maxSize
template <class T>
int Stack<T>::getmaxSize() const {
	return maxSize;
}

#endif // STACK_H

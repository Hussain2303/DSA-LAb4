#include <iostream>
#include <string>
#include "myStack.h" 

using namespace std;

int main() {
	const int maxSize = 100;
	myStack<string> obj(maxSize);

	while (true) {
		cout << "\nLibrary Management System\n";
		cout << "1. Push book onto stack\n";
		cout << "2. Reverse stack\n";
		cout << "3. Display stack\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: ";

		int choice;
		cin >> choice;
		cin.ignore();

		switch (choice) {
		case 1: {
					string bookTitle;
					cout << "Enter the book title: ";
					getline(cin, bookTitle);
					obj.push(bookTitle);
					cout << "Added \"" << bookTitle << "\" to the stack." << endl;
					break;
		}
		case 2: {
					myStack<string> reversedStack = reverseStack(obj);
					obj = reversedStack; 
					cout << "Stack reversed successfully." << endl;
					break;
		}
		case 3: {
					if (obj.isEmpty()) {
						cout << "The stack is empty." << endl;
					}
					else {
						obj.display();
					}
					break;
		}
		case 4: {
					cout << "Exiting the system." << endl;
					
		}
			return 0;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	}
	
}

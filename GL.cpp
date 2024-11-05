#include<iostream>
#include"myStack.h"
using namespace std;

string reverseString(const string & word)
{
	myStack<char> obj(word.length());
	for (char ch : word)
	{
		obj.push(ch);
	}
	string reversed = "";
	while (!obj.isEmpty())
	{
		reversed += obj.top();
		obj.pop();
	}
	return reversed;
}
int main()
{
	string str;
	cout << "Enter a String" << endl;
	cin >> str;
	string reversedString = reverseString(str);
	cout << "Reversed String is" << reversedString << endl;
	return 0;
}
/*********************************************************************************************
*Author:					Austin Koos
*Date Created:				10/23/2015
*Last Modification Date:	10/23/2015
*Lab Number:				CST 211 Assignment 4
*Filename:					main.cpp
*
*Overview:
*	Tests the functionality of the templated Stack class.  Makes use of all the member
*	functions and constructors.
*
*Input:
*
*
*Output:
*	isEmpty function boolean value displayed to console as well as any thrown Exceptions
*
***********************************************************************************************/
#include <iostream>
#include <cmath>
#include "Stack.h"
using std::cout;
using std::endl;

int main()
{
	Stack<int> stack(5);
	Stack<double> stackDouble(5);
	int num = 5;
	int num1 = 6;
	int num2 = 7;

	double doub = 1.0;
	double doub2 = 2.0;
	double doub3 = 3.0;

	stackDouble.Push(&doub);
	stackDouble.Push(&doub2);
	stackDouble.Push(&doub3);

	stack.Push(&num);
	stack.Push(&num1);
	stack.Push(&num2);

	const Node<int> node = stack.Peek();

	Stack<int> stack1(stack);

	stack1.Push(&num1);
	stack1.Push(&num1);

	try
	{
		stack1.Push(&num1);
	}
	catch (Exception &except)
	{
		cout << except;
	}

	Iterator<int> newItBegin = stack.Begin();

	newItBegin++;
	++newItBegin;

	Iterator<int> newItBeginCopy(newItBegin);

	num = stack.Pop();

	cout << stack.isEmpty() << endl;
	cout << stack1.isFull() << endl;
 
	for (int i = 0; i < 6; i++)
	{
		try
		{
			cout << stack1.Pop() << endl;
		}
		catch (Exception &except)
		{
			cout << except;
		}
	}

	return 0;
}
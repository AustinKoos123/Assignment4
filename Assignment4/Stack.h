#ifndef STACK_H
#define STACK_H
#include "Iterator.h"
#include "Exception.h"

/************************************************************************
* Class: Stack
*
* Constructors:
*	Stack(int stackSize)
*		head and tail set to nullptr, numItems and stackSize to 0
*
*	Stack(const Stack& copy)
*		Copy constructor
*
* Destructor:
*	~Stack()
*		Deletes all the nodes in the linked list
*
* Methods:
*	Stack& operator= (const Stack& rhs)
*		If this and rhs are not the same, copies rhs to this
*
*	T& Peek()
*		Returns data at the top of the stack
*
*	void Push(T* element)
*		Adds an element to the top of the stack
*
*	T Pop()
*		Returns and deletes element at the top of the stack
*
*	int Size()
*		Returns numItems
*
*	bool isEmpty()
*		If the list is empty, returns true.  Otherwise, returns false
*
*	bool isFull()
*		Returns true if m_numItems == m_stackSize.  Otherwise, returns false
*
*	Iterator<T> Begin()
*		Returns an Iterator at the beginning of the list
*
*	void Purge()
*		Deletes all the nodes in the stack
*
*************************************************************************/

template <typename T>
class Stack {

public:
	//Default ctor
	Stack(int stackSize);

	//Dtor
	~Stack();

	//Copy ctor
	Stack(const Stack& copy);

	//Overloaded = operator
	Stack& operator= (const Stack& rhs);

	//Returns element at the front of the list
	const Node<T>& Peek();

	//Adds an element to the front of the list
	void Push(T* element);

	//Returns and deletes the element at the front of the list
	T Pop();

	//Returns numItems 
	int Size();

	//Returns true if list is empty, false otherwise
	bool isEmpty();

	//Returns true if list is full, false otherwise
	bool isFull();

	//Returns an Iterator at the beginning of the list
	Iterator<T> Begin();

	//Deletes all nodes in the list
	void Purge();

private:
	Node<T> *m_head;		//First node in the list
	Node<T> *m_tail;		//Last node in the list
	int m_numItems;			//Number of nodes in the list
	int m_stackSize;		//Max size of the stack
};

#include "Stack.tpp"

#endif

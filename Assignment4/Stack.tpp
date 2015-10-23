/**************************************************
* Purpose:
*	Default ctor
*
* Entry:
*	Object created using no paramters
*
* Exit:
*	head set to nullptr and numItems set to 0
**************************************************/
template <typename T>
Stack<T>::Stack(int stackSize) : m_head(nullptr), m_tail(nullptr), m_numItems(0), m_stackSize(stackSize)
{
	
}

/**************************************************
* Purpose:
*	dtor
*
* Entry:
*	Object to be destroyed
*
* Exit:
*	Object is destroyed
**************************************************/
template <typename T>
Stack<T>::~Stack()
{
	Purge();
}

/**************************************************
*	Purpose:	Copy constructor
*
*   Entry:		Object passed or returned by value or an
*				object instantiated with another object
*
*   Exit:		this object will be a copy of copy
*
**************************************************/
template <typename T>
Stack<T>::Stack(const Stack& copy) : m_head(nullptr), m_tail(nullptr), m_numItems(0), m_stackSize(0)
{
	*this = copy;
}

/*************************************************
*	  Purpose:		Operator= function
*
*     Entry:		Object assigned to another object
*
*     Exit:			this object will be a copy of rhs
*
***************************************************/
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& rhs)
{
	if (this != &rhs)
	{
		Purge();

		m_stackSize = rhs.m_stackSize;

		Node<T> *n = rhs.m_head;

		while (n != nullptr)
		{
			T temp = n->GetData();
			Push(&temp);
			n = n->GetNext();
		}
	}

	return *this;
}

/**************************************************
* Purpose:
*	Returns the first node of the list
*
* Entry:
*	Function called from invoking object
*
* Exit:
*	Element at the front of the list is returned
**************************************************/
template <typename T>
const Node<T>& Stack<T>::Peek()
{
	const Node<T> *n = m_head;
	return *n;
}

/**************************************************
* Purpose:
*	Adds a new node to the top of the stack
*
* Entry:
*	Element to add to the stack
*
* Exit:
*	Head points to the new Node, with element
*	copied to data
**************************************************/
template <typename T>
void Stack<T>::Push(T* element)
{
	if (m_numItems == m_stackSize)
	{
		throw Exception("Stack Overflow");
	}
	else
	{
		Node<T> *n = new Node<T>(*element);
		n->SetNext(m_head);

		if (m_numItems == 0)
		{
			m_head = n;
			m_tail = n;
			m_numItems++;
		}
		else
		{
			m_head->SetPrev(n);
			m_head = n;
			m_numItems++;
		}
	}
}

/**************************************************
* Purpose:
*	Returns the element at the front of the list and
*	deletes the first node
*
* Entry:
*	Function called from invoking object
*
* Exit:
*	Data is returned and node is deleted
**************************************************/
template <typename T>
T Stack<T>::Pop()
{
	if (m_numItems <= 0)
	{
		throw Exception("Stack Underflow");
	}
	else
	{
		if (m_numItems == 1)
		{
			Node<T> *n = m_head;
			T newData = n->GetData();
			m_head = m_head->GetNext();
			delete n;
			m_numItems--;

			return newData;
		}
		else
		{
			Node<T> *n = m_head;
			T newData = n->GetData();
			m_head = m_head->GetNext();
			m_head->SetPrev(nullptr);
			delete n;
			m_numItems--;

			return newData;
		}
	}
}

/**************************************************
* Purpose:
*	Returns the number of nodes in the list
*
* Entry:
*	Function called from invoking object
*
* Exit:
*	numItems is returned
**************************************************/
template <typename T>
int Stack<T>::Size()
{
	return m_numItems;
}

/**************************************************
* Purpose:
*	Returns true if numItems == 0, false otherwise
*
* Entry:
*	Function called by invoking object
*
* Exit:
*	True returned if numItems == 0, false otherwise
**************************************************/
template <typename T>
bool Stack<T>::isEmpty()
{
	bool retValue = false;
	if (m_numItems == 0)
	{
		retValue = true;
	}

	return retValue;
}

/**************************************************
* Purpose:
*	Returns true if m_numItems == m_stackSize.  
*	Otherwise, returns false
*
* Entry:
*	Function called by invoking object
*
* Exit:
*	True returned if numItems == m_stackSize, 
*	false otherwise
**************************************************/
template <typename T>
bool Stack<T>::isFull()
{
	bool retValue = false;
	if (m_numItems == m_stackSize)
	{
		retValue = true;
	}

	return retValue;
}

/**************************************************
* Purpose:
*	Returns an Iterator at the beginning of the list
*
* Entry:
*	Function called by invoking object
*
* Exit:
*	Iterator returned
**************************************************/
template <typename T>
Iterator<T> Stack<T>::Begin()
{
	Iterator<T> newIt;

	newIt.SetIterator(m_head);

	return newIt;
}

/**************************************************
* Purpose:
*	Deletes all the nodes in a LinkedList
*
* Entry:
*	Function called from invoking object
*
* Exit:
*	All nodes are deleted from this
**************************************************/
template <typename T>
void Stack<T>::Purge()
{
	while (m_numItems > 0)
	{
		Node<T> *n = m_head;
		m_head = m_head->GetNext();

		if (m_numItems > 1)
		{
			m_head->SetPrev(nullptr);
		}

		delete n;
		n = nullptr;
		m_numItems--;
	}

	m_stackSize = 0;
}


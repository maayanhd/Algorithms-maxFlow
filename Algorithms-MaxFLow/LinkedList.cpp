#include "LinkedList.h"

LinkedList::LinkedList() 
{
	MakeEmpty();
}
LinkedList::~LinkedList() {
	Node* currNode = m_Head;
	Node* tempNode = nullptr;

	while (currNode != nullptr)
	{
		tempNode = currNode->m_Next;
		delete currNode;
		currNode = tempNode;
	}

	m_ListSize = 0;
}
Node* LinkedList::Find(int dataToFind)
{
	Node* currNode = m_Head;
	while (currNode != nullptr)
	{
		if (currNode->m_Data == dataToFind)
		{
			return currNode;
		}
	}

	return nullptr;
}
void LinkedList::InsertToEnd(int dataToInsert)
{
	Node* newNode = new Node(dataToInsert);
	if (m_Tail == nullptr)
	{
		m_Head = m_Tail = newNode;
	}
	else
	{
		m_Tail->m_Next = newNode;
		m_Tail = newNode;
	}
}
void LinkedList::MakeEmpty()
{
	m_Head = m_Tail = nullptr;
	m_ListSize = 0;
}
bool LinkedList::IsEmpty()
{
	return m_ListSize == 0;
}
int LinkedList::First()
{
	return m_Head->m_Data;
}
int LinkedList::Last()
{
	return m_Tail->m_Data;
}
void LinkedList::InsertAfter(int nodeToFind,int dataToInsert)
{
	Node* foundNode = Find(nodeToFind);
	if (foundNode == nullptr)
	{
		cout << "There is no node with specified data" << endl;
	}
	else
	{
		foundNode->InsertAfter(new Node(dataToInsert));
		m_ListSize++;
	}
}
void LinkedList::DeleteNode(int dataToDelete)
{
	Node* prevNode = nullptr;
	Node* currNode = m_Head;
	bool found = false;

	while (currNode != nullptr)
	{
		if (currNode->m_Data == dataToDelete)
		{
			found = true;

			if (currNode == m_Head)
			{
				m_Head = currNode->m_Next;
				delete currNode;
			}
			else
			{
				prevNode->m_Next = currNode->m_Next;
				delete currNode;
			}
		}
		prevNode = currNode;
		currNode = currNode->m_Next;
	}

	if (found == false)
	{
		cout << "There is no node with specified data" << endl;
	}
	else
	{
		m_ListSize--;
	}
}
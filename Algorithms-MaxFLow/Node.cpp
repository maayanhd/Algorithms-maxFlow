#include "Node.h"

Node::Node(int data, Node* next)
{
	m_Data = data;
	m_Next = next;
}

Node::Node()
{
	m_Next = nullptr;
}

Node::~Node()
{
}

void Node::InsertAfter(Node* nodeToInsert)
{
	nodeToInsert->m_Next = m_Next;
	m_Next = nodeToInsert;
}

Node* Node::DeleteAfter()
{
	Node* temp = m_Next;
	if (m_Next == nullptr)
		return nullptr;

	m_Next = temp->m_Next;
	return temp;
}
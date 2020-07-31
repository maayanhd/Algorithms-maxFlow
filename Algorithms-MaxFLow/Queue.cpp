#include "Queue.h"

void Queue::ClearQueue()
{
	while (this->IsEmpty() == false)
	{
		this->Dequeue();
	}
	delete m_Front;
}

void Queue::MakeEmpty()
{
	m_Front = new Node();
	m_Rear = m_Front;
}

Queue::Queue()
{
	MakeEmpty();
}

bool Queue::IsEmpty() 
{
	return (m_Front == m_Rear);
}

Queue::~Queue()
{
	ClearQueue();
}

int Queue:: Dequeue() 
{
	NotifyEmptyQueueError();
	
	Node* temp = m_Front->DeleteAfter();
	int data = temp->m_Data;
	if (m_Rear == temp)
		m_Rear = m_Front;
	delete temp;
	return data;
}

void Queue::Enqueue(int dataToInsert) 
{
	Node* newNode = new Node(dataToInsert);
	m_Rear->InsertAfter(newNode);
	m_Rear = newNode;
}

int Queue::Front()
{
	NotifyEmptyQueueError();

	return (m_Front->m_Next->m_Data);
}

void Queue::NotifyEmptyQueueError()
{
	if (IsEmpty())
	{
		cout << "Error: The Queue is Empty" << endl;
		exit(1);
	}
}
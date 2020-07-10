#pragma once

#include "Node.h"

class LinkedList
{
private:

	Node* m_Head;
	Node* m_Tail;
	int m_ListSize;

	Node* Find(int dataToFind);

public:

	LinkedList();
	~LinkedList();
	void MakeEmpty();
	bool IsEmpty();
	int First();
	int Last();
	void InsertToEnd(int dataToInsert);
	void InsertAfter(int nodeToFind, int dataToInsert);
	void DeleteNode(int dataToDelete);
	inline int getListSize() { return m_ListSize; }

};


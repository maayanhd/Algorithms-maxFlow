#pragma once

#include <iostream>
#include <stdio.h>

using namespace std;

class Node
{
     public:

	     int m_Data;
	     Node* m_Next;

	     Node(int data, Node* next = nullptr);
	     Node();
	     ~Node();
	     void InsertAfter(Node* nodeToInsert);
	     Node* DeleteAfter();
};


#ifndef __NODE_H
#define __NODE_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

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

#endif

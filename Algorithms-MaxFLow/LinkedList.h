#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

#include "Node.h"

class LinkedList
{
     private:

	     Node* m_Head;
	     Node* m_Tail;
	     int m_ListSize;

          // Service function
	     Node* find(int dataToFind);

     public:

	     LinkedList();
	     ~LinkedList();
	     void MakeEmpty();
	     bool IsEmpty();
          const Node* GetFirst() const
          {
               return m_Head;
          };

          const Node* GetLast() const
          {
               return m_Tail;
          };

	     void InsertToEnd(int dataToInsert);
	     void InsertAfter(int nodeToFind, int dataToInsert);
	     void DeleteNode(int dataToDelete);
	     inline int getListSize() { return m_ListSize; }

};

#endif


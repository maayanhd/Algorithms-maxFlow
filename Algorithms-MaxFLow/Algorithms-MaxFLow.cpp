// Algorithms-MaxFLow.cpp : This file contains the 'main' function. Program execution begins and ends there.
// In order to send in argv a name of file to the main please click on the properties of the project
// then choose the debugging option (under Configuration Properties). 
// Now copy the Command Arguments the name of the text file with its suffix (nameFile.txt) 
// press ctrl + F5 as usual to execute the program as usual
// In addition- the 2 versions of FordFulkerson are printing their output independently and operating on the same graph

#include "FileInputHandling.h"

int main(int argc, char* argv[])
{
     if (argc > 2)
	{
		cout << "Error: The program must receive 2 arguments only" << endl;
		exit(1);
	}
     else
     {
        string fileName(argv[1]);
		//ifstream inFile1(fileName, ios::in);

      //  FlowNetworkGraph* graph1= FileInputHandling::InitializeGraphFromFile(inFile1);
	//	graph1->FordFulkersonUsingBfs();
	//	delete graph1;
		ifstream inFile2(fileName, ios::in);
		FlowNetworkGraph* graph2 = FileInputHandling::InitializeGraphFromFile(inFile2);
		graph2->FordFulkeronsUsingDijkstra();
		delete graph2;
	}
     
     return 0;
}




// Algorithms-MaxFLow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
          //string fileName("input1.txt");
		ifstream inFile(fileName, ios::in);

          FlowNetworkGraph* currentGraph= FileInputHandling::InitializeGraphFromFile(inFile);
		currentGraph->FordFulkersonUsingBfs();
          
		delete currentGraph;
	}
     
     return 0;
}




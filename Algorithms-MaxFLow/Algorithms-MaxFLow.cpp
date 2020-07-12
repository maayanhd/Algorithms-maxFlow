// Algorithms-MaxFLow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "FlowNetworkGraph.h"
#include <fstream>

FlowNetworkGraph* InitializeGraphFromFile(ifstream& graphData)
{
	FlowNetworkGraph* resGraph = nullptr;

	if (graphData.is_open())
	{
		int n, m, u, v, s, t;
		float c;
		graphData >> n;
		graphData >> m;
		graphData >> s;
		graphData >> t;

		resGraph = new FlowNetworkGraph(n, s, t);

		for (int i = 0; i < m; i++)
		{
			graphData >> u;
			graphData >> v;
			graphData >> c;
			resGraph->AddEdge(u, v, c);
		}
     }
	else
	{
		cout << "Error: File not found" << endl;
		exit(1);
	}

	return resGraph;
}

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

          FlowNetworkGraph* currentGraph= InitializeGraphFromFile(inFile);
		currentGraph->FordFulkersonUsingBfs();
          
		delete currentGraph;
	}
     
     return 0;
}




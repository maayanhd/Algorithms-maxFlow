// Algorithms-MaxFLow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "WeightedDirectedGraph.h"
#include <fstream>

int Main(int argc, char* argv[])
{
	if (argc > 2)
	{
		cout << "Error: The program must recieve 2 arguments only" << endl;
		exit(1);
    }
	else
	{
		int s, t;
		string fileName(argv[1]);
		ifstream inFile(fileName);
		WeightedDirectedGraph* currentGraph = InitializeGraphFromFile(inFile,s,t);






		delete currentGraph;
	}
}

WeightedDirectedGraph* InitializeGraphFromFile(ifstream &graphData,int& s,int& t)
{
	WeightedDirectedGraph* resGraph = nullptr;

	if (graphData.is_open())
	{
		int n, m, u, v;
		float c;
		graphData >> n;
		graphData >> m;
		graphData >> s;
		graphData >> t;

		resGraph = new WeightedDirectedGraph(n);
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


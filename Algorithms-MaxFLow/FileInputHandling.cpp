#include "FileInputHandling.h"
#include <sstream>
FlowNetworkGraph* FileInputHandling::InitializeGraphFromFile(ifstream& graphData)
{
	FlowNetworkGraph* resGraph = nullptr;
	stringstream inputStreamStr;
	if (graphData.is_open())
	{

		int n, m, u, v, s, t, c;

		inputStreamStr = GetStringStreamFromFile(graphData);
		ReadIntFromStream(inputStreamStr, n);
		inputStreamStr = GetStringStreamFromFile(graphData);
		ReadIntFromStream(inputStreamStr, m);
		inputStreamStr = GetStringStreamFromFile(graphData);
		ReadIntFromStream(inputStreamStr, s);
		inputStreamStr = GetStringStreamFromFile(graphData);
		ReadIntFromStream(inputStreamStr, t);

		resGraph = new FlowNetworkGraph(n, s, t);

		int itr = 0;
		for (int i = 0; i < m; i++, itr++)
		{
			inputStreamStr = GetStringStreamFromFile(graphData);
			ReadIntFromStream(inputStreamStr, u);
			ReadIntFromStream(inputStreamStr, v);
			ReadIntFromStream(inputStreamStr, c);
			resGraph->AddEdge(u, v, c);
		}

		// Making sure all characters has been read
		char lastCharacterToClean;
		graphData >> lastCharacterToClean;

		// Assuring we finished read the file at this point as we should have
		if (!graphData.eof())
		{
			NotifyInputError();
		}
	}
	else
	{
		cout << "Error: File not found" << endl;
		exit(1);
	}

	return resGraph;
}

stringstream FileInputHandling::GetStringStreamFromFile(ifstream& graphData)
{
	string inputStr;
	getline(graphData, inputStr);

	return stringstream(inputStr);
}
void FileInputHandling::ReadIntFromStream(stringstream& streamStr, int& inputVal)
{
	streamStr >> inputVal;

	if (streamStr.fail())
	{
		NotifyInputError();
	}

	//Clearing error flags
	streamStr.clear();
}

void FileInputHandling::NotifyInputError()
{
	cout << "invalid input" << endl;
	exit(1);
}
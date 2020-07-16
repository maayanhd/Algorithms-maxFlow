#include "FileInputHandling.h"

FlowNetworkGraph* FileInputHandling::InitializeGraphFromFile(ifstream& graphData)
{
     FlowNetworkGraph* resGraph = nullptr;

     if (graphData.is_open())
     {
          int n, m, u, v, s, t, c;

          ReadIntFromStream(graphData, n);
          ReadIntFromStream(graphData, m);
          ReadIntFromStream(graphData, s);
          ReadIntFromStream(graphData, t);
          
          resGraph = new FlowNetworkGraph(n, s, t);
          
          int itr = 0;
          for (int i = 0; i < m; i++, itr++)
          {
               ReadIntFromStream(graphData, u);
               ReadIntFromStream(graphData, v);
               ReadIntFromStream(graphData, c);
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

void FileInputHandling::ReadIntFromStream(ifstream& graphData, int& inputVal)
{
     graphData >> inputVal;

     if (graphData.fail())
     {
          NotifyInputError();
     }

     //Clearing error flags
     graphData.clear();
}

void FileInputHandling::NotifyInputError()
{
     cout << "invalid input" << endl;
     exit(1);
}
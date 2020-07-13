#ifndef _FILEINPUTHANDLING__H
#define _FILEINPUTHANDLING__H

#include "FlowNetworkGraph.h"

class FileInputHandling
{
     public:
          static void ReadCharFromStream(ifstream& graphData, int& inputVal);
          static FlowNetworkGraph* InitializeGraphFromFile(ifstream& graphData);
          static void NotifyInputError(); // Notifies the user for an invalid input
                                          // And exiting the program
};

#endif
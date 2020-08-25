#ifndef _FILEINPUTHANDLING__H
#define _FILEINPUTHANDLING__H

#include "FlowNetworkGraph.h"
#include <string>

class FileInputHandling
{
     public:
         static void ReadIntFromStream(stringstream& streamStr, int& inputVal);
         static stringstream GetStringStreamFromFile(ifstream& graphData);
         static FlowNetworkGraph* InitializeGraphFromFile(ifstream& graphData);
         static void NotifyInputError(); // Notifies the user for an invalid input
                                          // And exiting the program
};

#endif
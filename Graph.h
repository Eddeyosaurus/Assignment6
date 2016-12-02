#ifndef GRAPH_
#define GRAPH_

#include <sstream>
#include <iostream>
#include "List.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;


class Graph{
	public:
		Graph();
		~Graph();
		Graph(const Graph& other);
		Graph& operator=(const Graph& other);

		void SetNumNodes();
		//Sets the number of nodes in the graph;
		//Pre: 
		//Post: numNodes is set;
		
		void SetAdjList(); 
		//Sets each nodes adjcencies
		//Pre: SetNumNodes has been called
		//Post: All adjacencies set.
        
        int GetNumNodes();
        
        void BreadthFirstSearch(int s);
        
        void DepthFirstSearch(int s);
        
        void PrintAdjLists();
        
        void PrintBFS();
        
        void PrintDFS();

	private:
        int CheckInput(string input);
        
        void SetDiscovered();
        
        bool IsDiscovered(int s);
        
		int numNodes;
        
        bool* discovered;
        
        int numDiscovered;
        
        int* dfsArray;
        
        int* bfsArray;

		List* adjList;
        
        Queue bfsQ;
        
        Stack dfsStack;

};
#endif

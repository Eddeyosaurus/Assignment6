#ifndef GRAPH_
#define GRAPH_

#include <sstream>
#include <iostream>
#include <limits>
#include <limits.h>
#include <stdio.h>
#include "List.h"
#include "Queue.h"
#include "UnionFind.h"

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

		void PrintAdjLists();
        
        int GetNumNodes();
       
        void Prims(int);

        void PrintMST();

        void KruskalMST();

	private:
        int CheckInput(string input);
        
        void SetDiscovered();
        
        bool IsDiscovered(int s);

        void InitializeKeys();
        
		int numNodes;
        
        bool* discovered;

		List* adjList;

        int* key;

        int* mst;

        Queue Pqueue;

        int edges;

};
#endif

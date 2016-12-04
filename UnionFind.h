#ifndef UNION_FIND
#define UNION_FIND

#include <stdio.h>

using namespace std;

class UnionFind
{
	public:

		struct Edge
		{
			int source;
			int destination;
			int weight;
			bool operator<(const Edge rhs)
			{
				return weight < rhs.weight;
			}
			bool operator>(const Edge rhs)
			{
				return rhs.weight < weight;
			}
			Edge& operator=(Edge other)
			{
				source = other.source;
				destination = other.destination;
				weight = other.weight;
			}
		};

		struct Subset
		{
			int parent;
			int rank;
		};

		UnionFind(int numNodes, int edge);

		~UnionFind();

		void AddEdge(int, int, int);

		int Find(int);

		bool isCycle();

		void Union(int x, int y);

		void InitializeSubsets();

		void QuickSort();

		void GottaGoFast(Edge* arr, int, int);

		void MakeMST();

		void PrintResults();

	private:

		Edge* results;
		Edge* edges;
		Subset* subsets;
		int V;
		int E;
		int edgeIndex;
		int resultsLength;



};
#endif
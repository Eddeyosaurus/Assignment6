#include "UnionFind.h"


UnionFind::UnionFind(int numNodes, int edge)
{
	V = numNodes;
	E = edge;
	edgeIndex = 0;
	subsets = new Subset[V];
	edges = new Edge[E];
	results = new Edge[V];
}

UnionFind::~UnionFind()
{
	delete [] edges;
	delete [] subsets;

}

void UnionFind::AddEdge(int s, int d, int w)
{
	edges[edgeIndex].source = s;
	edges[edgeIndex].destination = d;
	edges[edgeIndex].weight = w;
	edgeIndex++;
}

int UnionFind::Find(int i)
{
	if(subsets[i].parent != i)
		subsets[i].parent = Find(subsets[i].parent);

	return subsets[i].parent;
}


void UnionFind::Union(int x, int y)
{
	// printf("%s\n", "in UNION(X,Y)");
	// printf("%s%d\n", "X: ", x);
	// printf("%s%d\n", "Y: ", y);
	int xroot = Find(x);
	int yroot = Find(y);
	// printf("%s\n", "after Find");
	if(subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if(subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;
	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}

}

void UnionFind::InitializeSubsets()
{
	for(int i = 0; i < V; i++){
		subsets[i].parent = i;
		subsets[i].rank = 0;
	}
}

void UnionFind::QuickSort()
{
	GottaGoFast(edges, 0, E - 1);
}

void UnionFind::GottaGoFast(Edge* arr, int left, int right)
{
    int i = left, j = right;
    Edge temp;
    Edge pivot = arr[(left + right) / 2];
    
    while(i <= j){
        while(arr[i] < pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        
        if(i <= j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    
    if(left < j)
        GottaGoFast(arr, left, j);
    if(i < right)
        GottaGoFast(arr, i, right);
}

void UnionFind::MakeMST()
{
	// printf("%s\n", "In MakeMST");
	int e = 0;
	int i = 0;

	QuickSort();

	InitializeSubsets();

	while(e < V - 1)
	{
		struct Edge next = edges[i++];
		// printf("%s\n", "next = edges[i++]");

		int x = Find(next.source);
		int y = Find(next.destination);

		// printf("%s\n", "after Find");

		if(x != y)
		{
			// printf("%s\n", "in if");
			
			results[e++] = next;
			Union(x, y);

			// printf("%s\n", "after Union(x, y)");

		}
	}
	resultsLength = e;
}

void UnionFind::PrintResults()
{
	printf("\n%s\t%s\t%s\n\n", "SOURCE", "DESTINATION", "WEIGHT");

	for(int i = 0; i < resultsLength; i++)
		printf("%d\t%d\t\t%d\n", results[i].source, 
			results[i].destination, results[i].weight);
}

	
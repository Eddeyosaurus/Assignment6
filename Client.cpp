#include "Graph.h"

int main()
{
	cout << "\n\nCompiled\n\n";

	Graph test;

	test.SetNumNodes();

	test.SetAdjList();
    
    cout << "\n\n";
    
	test.PrintAdjLists();

	// cout << "Starting Node: ";

	// int temp;

	//cin >> temp;

	//test.Prims(temp);

	//test.PrintMST();

	test.KruskalMST();

	cout << "\n\nEND EXECUTION\n\n";

	return 0;
}
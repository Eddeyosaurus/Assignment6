#include "Graph.h"




Graph::Graph()
{
    adjList = NULL;
    mst = NULL;
    discovered = NULL;
    key = NULL;
    edges = 0;
}




Graph::~Graph()
{
    delete [] adjList;
}




Graph::Graph(const Graph& other)
{
    numNodes = other.numNodes;
    adjList = other.adjList;	
}




Graph& Graph::operator=(const Graph& other)
{
    numNodes = other.numNodes;
    adjList = other.adjList;
}




void Graph::SetNumNodes()
{
    string temp;
    int n;
    
    cout << "How many nodes in the graph? ";
    cin >> n;
    
    cout << "\n\n";
    
    numNodes = n;
    
    adjList = new List[n];
}




void Graph::SetAdjList()
{
    int num, weight;
    
    for(int i = 0; i < numNodes; i++){
        cout << "\n|NODE " << i << "|";

        cout << "\nConnecting node (enter a char to exit): ";

        while(cin >> num)
        {   
            cout << "Weight: ";
            
            cin >> weight;

            adjList[i].Insert(num, weight);
            edges++;
            cout << "\nConnecting node (enter a char to exit): ";
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}




int Graph::GetNumNodes()
{
    return numNodes;
}




void Graph::SetDiscovered()
{
    for(int i = 0; i < numNodes; i++)
        discovered[i] = false;
}




bool Graph::IsDiscovered(int s)
{
    if(discovered[s] == true)
        return true;
    else
        return false;
}




void Graph::PrintAdjLists()
{
    for(int i = 0; i < numNodes; i++){
        cout << "Node " << i;
        adjList[i].Print();
        cout << " -> NULL\n\n";
    }
}




void Graph::InitializeKeys()
{
    key = new int[numNodes];

    for(int i = 0; i < numNodes; i++)
    {
        key[i] = INT_MAX;
    }
}


void Graph::Prims(int initial)
{
    if(mst)
    {
        delete [] mst;
        mst = NULL;
    }
    if(discovered)
    {
        delete [] discovered;
        discovered = NULL;
    }
    if(key)
    {
        delete [] key;
        key = NULL;
    }
    discovered = new bool[numNodes];
    SetDiscovered();
    InitializeKeys();
    mst = new int[numNodes];
    
    Pqueue.Enqueue(initial, 0);
    int index = 0;

    while(!Pqueue.IsEmpty())
    {
        int u = Pqueue.Dequeue();

        discovered[u]  = true;
        //printf("\n%s%d\n", "U: ", u);

        adjList[u].Reset();

        if(!adjList[u].Empty())
        {
            do{
                int v = adjList[u].GetData();
                int weight = adjList[u].GetWeight();

                if(key[v] > weight && discovered[v] == false)
                {
                    key[v] = weight;
                    Pqueue.Enqueue(v, key[v]);
                    mst[v] = u;
                }
            }while(adjList[u].GetNext());
        }

    }
}


void Graph::PrintMST()
{
    printf("\n\n%s\n\n", "MINIMUM SPANNING TREE");
    for(int i = 1; i < numNodes; i++){
        printf("%d - %d\n",mst[i], i);
    }
}

void Graph::KruskalMST()
{
    UnionFind uFind(numNodes, edges);
    int i = 0;
    int j = 0;
    
    for(int k = 0; k < numNodes; k++){
        if(!adjList[k].Empty())
        {
            adjList[k].Reset();
            uFind.AddEdge(k, adjList[k].GetData(), adjList[k].GetWeight());
            // printf("\n%s%d%s%d\n", "source: ", k, "\tdestination: ", adjList[k].GetData());
            while(adjList[k].GetNext())
            {
                // printf("\n%s%d%s%d\n", "source: ", k, "\tdestination: ", adjList[k].GetData());
                uFind.AddEdge(k, adjList[k].GetData(), adjList[k].GetWeight());
            }
        }
    }

    // printf("%s\n", "after for loop");

    // printf("%s\n", "after quicksort");

    // printf("%s\n", "after subsets initialization");

    uFind.MakeMST();

    uFind.PrintResults();

    // printf("%s\n", "after MakeMST");

}



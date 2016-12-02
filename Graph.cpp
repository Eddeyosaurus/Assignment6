#include "Graph.h"




Graph::Graph()
{
    adjList = NULL;
    numDiscovered = 0;
}




Graph::~Graph()
{
    delete [] dfsArray;
    delete [] bfsArray;
    delete [] discovered;
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
    
    discovered = new bool[n];
    
    adjList = new List[n];
}




void Graph::SetAdjList()
{
    int num;
    string input;
    
    for(int i = 0; i < numNodes; i++)
    {
        cout << "\nPlease enter connecting nodes for node " << i << "(-1 to end):";
        
        cin >> num;
        
        cout << endl;
        
        while(num != -1)
        {
            adjList[i].Insert(num);
            
            cout << "Please enter next node: ";
            
            cin >> num;
            
            cout << endl;
        }
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




void Graph::BreadthFirstSearch(int s)
{
    int count = 0;
    
    bfsArray = new int [numNodes];
    
    SetDiscovered();
    discovered[s] = true;
    
    bfsArray[count] = s;
    count++;
    
    bfsQ.Enqueue(s);
    
    while(!bfsQ.IsEmpty())
    {
        int i = bfsQ.Dequeue();
        
        adjList[i].Reset();
        
        int j = adjList[i].GetData();
        
        if(!discovered[j]){
            discovered[j] = true;
            bfsQ.Enqueue(j);
            bfsArray[count] = j;
            count++;
        }
        
        while(adjList[i].GetNext()){
            j = adjList[i].GetData();
            
            if(!discovered[j]){
                discovered[j] = true;
                bfsQ.Enqueue(j);
                bfsArray[count] = j;
                count++;
            }
        }
    }
}




void Graph::DepthFirstSearch(int s)
{
    dfsStack.Push(s);
    
    SetDiscovered();
    int arr[numNodes];
    int count = 0;
    
    while(!dfsStack.IsEmpty()){
        
        int i = dfsStack.Pop();
        
        if(discovered[i] == false)
        {
            arr[count] = i;
            count++;
            discovered[i] = true;
            numDiscovered++;
            adjList[i].Reset();
            dfsStack.Push(adjList[i].GetData());
            
            while(adjList[i].GetNext()){
                dfsStack.Push(adjList[i].GetData());
            }
        }
        
    }
    
    dfsArray = new int [count];
    
    for(int i = 0; i < numNodes; i++)
    {
        dfsArray[i] = arr[i];
    }
        
}




void Graph::PrintAdjLists()
{
    for(int i = 0; i < numNodes; i++){
        cout << "Node " << i << " connected to: ";
        adjList[i].Print();
        cout << "\n\n";
    }
}




void Graph::PrintBFS()
{
    for(int i = 0; i < numNodes; i++)
        cout << bfsArray[i] << " ";
}




void Graph::PrintDFS()
{
    for(int i = 0; i < numNodes; i++)
        cout << dfsArray[i] << " ";
}


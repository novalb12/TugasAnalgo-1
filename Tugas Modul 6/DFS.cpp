#include<iostream> 
#include<list> 
using namespace std; 

class Graph 
{ 
    int V; 
    list<int> *adj; 
    void DFSUtil(int v, bool visited[]); 
public: 
    Graph(int V);
    void addEdge(int v, int w); 
    void DFS(int v); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w);
} 
  
void Graph::DFSUtil(int v, bool visited[]) 
{ 
    visited[v] = true; 
    cout << v << " "; 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
} 
 
void Graph::DFS(int v) 
{ 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
    DFSUtil(v, visited); 
} 
  
int main() 
{ 
	int node,start;
	cout<<"Input the amount of your nodes : ";cin>>node;
    Graph g(node);
    cout<<"Instructions :"<<endl;
    cout<<"1. Enter the number of nodes from 0 to n-1"<<endl;
    cout<<"2. Enter negative numbers (such as -1) on either node input to to exit the program"<<endl;
    for(;;){
    	int node1,node2;
    	cout<<"Enter number between "<<0<<" to "<<node-1<<endl;
    	cout<<"Input node 1 : ";cin>>node1;
    	cout<<"Input node 2 : ";cin>>node2;
    	if(node1>=0&&node2>=0&&node1<node&&node2<node){
    		g.addEdge(node1,node2);
    		cout<<endl;
		}
		else if(node1<0||node2<0)
			break;
		else
			cout<<"Wrong input. Please enter again"<<endl;
	}
	back:
	cout<<"\nNode starts from : ";cin>>start;
	if(start<0||start>node-1){
		cout<<"Wrong input. Please enter again"<<endl;
		goto back;
	}
    cout<<"Your Depth First Traversal (starting from vertex "<<start<<")"<<endl; 
    g.DFS(start);
    return 0; 
}
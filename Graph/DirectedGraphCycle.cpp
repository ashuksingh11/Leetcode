// Time Complexity: O(V + E)
// Space Complexity: O(V)

class Solution{
public:
	bool isCyclicUtil(int v, vector<bool> &visited, vector<bool> &recStack, vector<int> adj[]){
        
	    if(visited[v] == false) { 
			visited[v] = true; 
			recStack[v] = true; 

			//calling function recursively for all the vertices adjacent to this vertex.
			for(int i = 0; i < adj[v].size(); ++i) { 
				if ( !visited[adj[v][i]] && isCyclicUtil(adj[v][i], visited, recStack, adj)) 
					return true; 
				else if (recStack[adj[v][i]]) 
					return true; 
			} 
		} 
		recStack[v] = false;    //removing the vertex from recursion stack
		return false;                                                                                                            
	}


	bool isCyclic(int V, vector<int> adj[]){
		vector<bool> visited(V, false); 
		vector<bool> recStack(V, false); 
		for(int i = 0; i < V; i++) 
			if(isCyclicUtil(i, visited, recStack, adj)) 
				return true;
		return false;
	}
};

//kahn's algo

// Time Complexity: O(V + E)
// Space Complexity: O(V)

#include<bits/stdc++.h> 
using namespace std; 

void topologicalSort(vector<int> adj[], int V) { 
    vector<int> in_degree(V, 0); 
  
    for (int u = 0; u < V; u++) { 
        for (int x:adj[u]) 
            in_degree[x]++; 
    } 
  
    queue<int> q; 
    for (int i = 0; i < V; i++) 
        if (in_degree[i] == 0) 
            q.push(i); 

    int count=0;  
    while (!q.empty()) { 
        int u = q.front(); 
        q.pop(); 
  
        for (int x: adj[u]) 
            if (--in_degree[x] == 0) 
                q.push(x); 
        count++;
    } 
    if (count != V) 
        cout << "There exists a cycle in the graph\n"; 
    else
        cout << "There exists no cycle in the graph\n";
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

int main() { 
	int V=5;
	vector<int> adj[V];
	addEdge(adj,0, 1); 
    addEdge(adj,4, 1); 
    addEdge(adj,1, 2); 
    addEdge(adj,2, 3); 
    addEdge(adj,3, 1);  
  
    topologicalSort(adj,V);

	return 0; 
} 
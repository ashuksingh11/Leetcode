class Solution {
  public:
    bool dfs(int node,int parent ,vector<int> adj[] ,vector<bool>& visited){
        visited[node] = true;
        for(auto adjcentNode : adj[node]){
            if(!visited[adjcentNode]){
                if(dfs(adjcentNode , node , adj , visited))
                    return true;
            }
            
            else if(adjcentNode != parent)return true;
        }
        return false;
        
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        for(int i = 0; i<V; i++){
            if(!visited[i]){
               if( dfs(i , -1 , adj , visited))
                return true;
            }
        }
        return false;
    }
};
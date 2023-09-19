//323. Number of Connected Components in an Undirected Graph
//https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int count = 0;
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                count++;
                dfs(graph,i,visited);
            }
        }

        return count;
    }

    void dfs(vector<vector<int>>& g, int node, vector<bool>& visited) {
        if(visited[node]) {
            return;
        }

        visited[node] = true;
        for(auto neighbor:g[node]) {
            dfs(g, neighbor, visited);
        }
    }
};
//261. Graph Valid Tree
//https://leetcode.com/problems/graph-valid-tree/description/

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        if(n-1 != edges.size()) {
            return false;
        }

        for(auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> seen;
        bool nocycle = dfs(graph,0,-1,seen);
        return  nocycle && seen.size() == n;
    }

    bool dfs(vector<vector<int>>& graph, int node, int parent, unordered_set<int>&seen) {
        if(seen.count(node)) {
            return false;
        }
        seen.insert(node);

        for(auto neighbor: graph[node]) {
            if(neighbor != parent && !dfs(graph, neighbor,node,seen)) {
                return false;
            }
        }

        return true;
    }
};
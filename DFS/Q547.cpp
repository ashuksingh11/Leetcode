//547. Number of Provinces
//https://leetcode.com/problems/number-of-provinces/description/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int numofcomponents = 0;
        vector<bool> visited(n,false);

        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                numofcomponents++;
                dfs(isConnected, i, visited);
            }
        }

        return numofcomponents;
    }

    void dfs(vector<vector<int>>& isConnected, int node, vector<bool>& visited) {
        visited[node] = true;

        for(int i=0; i<isConnected.size(); i++) {
            if(isConnected[node][i] && !visited[i]) {
                dfs(isConnected, i, visited);
            }
        }
    }
};
//797. All Paths From Source to Target
//https://leetcode.com/problems/all-paths-from-source-to-target/description/


class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = graph.size() - 1;
        vector<int> path{0};

        backtrack(graph, 0, path, target);

        return result;
    }

    void backtrack(vector<vector<int>>& graph, int currnode, vector<int>& path, int target) {
        if(currnode == target) {
            result.push_back(path);
            return;
        }

        for(auto& nextnode : graph[currnode]) {
            path.push_back(nextnode);
            backtrack(graph, nextnode, path, target);
            path.pop_back();
        }
    }
};
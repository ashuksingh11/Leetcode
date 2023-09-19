//https://leetcode.com/problems/all-paths-from-source-lead-to-destination/description/
//1059. All Paths from Source Lead to Destination

class Solution {
public:
    enum class Color {NONE, GRAY,BLACK};

    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n, vector<int>{});

        for(auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
        }

        vector<Color> color(n, Color::NONE);
        return dfs(graph, source, destination, color);
    }

    bool dfs(vector<vector<int>>& graph, int currnode, int dest, vector<Color>& color) {
        //if gray then loop return false
        if(color[currnode] != Color::NONE) {
            return color[currnode] == Color::BLACK;
        }

        // If curr node does not have neighbors then it should be dest or ret false
        if(graph[currnode].size() == 0) {
            return currnode == dest;
        }

        //now we are processing this node mark as gray
        color[currnode] = Color::GRAY;
        for(auto nextnode: graph[currnode]) {
            if(!dfs(graph, nextnode, dest, color)) {
                return false;
            }
        }

        //recursive processing done for node mark as black
        color[currnode] = Color::BLACK;
        return true;
    }
};
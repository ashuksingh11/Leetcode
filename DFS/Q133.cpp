//133. Clone Graph
//https://leetcode.com/problems/clone-graph/description/

class Solution {
public:
    unordered_map<Node*, Node*> visited;
    Node* cloneGraph(Node* node) {
        if(node == nullptr) {
            return nullptr;
        }

        if(visited.find(node) != visited.end()) {
            return visited[node];
        }

        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;

        for(auto& neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return cloneNode;
    }
};
//261. Graph Valid Tree
//https://leetcode.com/problems/graph-valid-tree/description/

class UnionFind {
    private:
    vector<int> root, rank;
    public:
    UnionFind(int n) {
        root.resize(n);
        rank.resize(n);

        for(int i=0; i<n; i++) {
            root[i] = i;
            rank[i] = 1;
        }

    }

    int find(int x) {
        if(x != root[x]) {
            root[x] = find(root[x]);
        }

        return root[x];
    }

    bool unionset(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if(rootX == rootY) {
            return false;
        }

        if(rank[rootX] < rank[rootY]) {
            root[rootX] = rootY;
        }
        else if(rank[rootX] > rank[rootY]) {
            root[rootY] = rootX;
        }
        else {
            root[rootY] = rootX;
            rank[rootX]++;
        }

        return true;
    }


};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n-1 != edges.size()) {
            return false;
        }

        UnionFind uf(n);

        for(auto edge: edges) {
            int x = edge[0];
            int y = edge[1];
            if(!uf.unionset(x,y)) {
                return false;
            }
        }

        return true;
    }


};
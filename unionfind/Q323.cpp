//323. Number of Connected Components in an Undirected Graph
//https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/

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

    int unionset(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);

        if(rootx == rooty) {
            return 0;
        }
        else {
            if(rank[rootx] < rank[rooty]) {
                root[rootx] = rooty;
            }
            else if(rank[rootx] > rank[rooty]) {
                root[rooty] = rootx;
            }
            else {
                root[rooty] = rootx;
                rank[rootx]++;
            }

            return 1;
        }
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int count = n;

        UnionFind uf(n);

        for(auto edge: edges) {
            count = count - uf.unionset(edge[0], edge[1]);
        }

        return count;
    }

};
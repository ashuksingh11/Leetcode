//547. Number of Provinces
//https://leetcode.com/problems/number-of-provinces/description/

class UnionFind {
    private:
        vector<int> root, rank;
        int count;

    public:
        UnionFind(int size) {
            root.resize(size);
            rank.resize(size);
            count = size;
            for(int i=0; i<size; i++) {
                root[i] = i;
            }
        }
        //find using path compression
        int find(int x) {
            if(x != root[x]) {
                root[x] = find(root[x]);
            }

            return root[x];
        }

        void unionset(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
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
        }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind dsu(n);

        int numofcomponents = n;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(isConnected[i][j] && dsu.find(i) != dsu.find(j)) {
                    numofcomponents--;
                    dsu.unionset(i,j);
                }
            }
        }

        return numofcomponents;
    }


};

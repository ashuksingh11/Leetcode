//909. Snakes and Ladders
//https://leetcode.com/problems/snakes-and-ladders/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        // we want to label cells from 1~36 (for n=6)
        vector<pair<int,int>> cells(n*n+1);
        int label = 1;
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);
        for(int row=n-1; row>=0; row--) {
            for(int col: columns) {
                cells[label] = {row,col};
                label++;
            }
            reverse(columns.begin(), columns.end());
        }

        vector<int> dist(n*n+1, -1);
        queue<int> q;
        dist[1] = 0;
        q.push(1);

        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(int next = curr+1; next <= min(curr+6, n*n); next++) {
                pair<int,int> rc = cells[next];
                int row = rc.first; int col = rc.second;
                int destination = board[row][col] == -1 ? next:board[row][col];
                if(dist[destination] == -1) {
                    dist[destination] = dist[curr] + 1;
                    q.push(destination);
                }
            }
        }

        return dist[n*n];
    }
};
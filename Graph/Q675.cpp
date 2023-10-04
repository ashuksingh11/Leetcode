//675. Cut Off Trees for Golf Event
//https://leetcode.com/problems/cut-off-trees-for-golf-event/description/
class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        // Given : Clear the trees in increasing order of height
        // constraints : n , m <= 50 = Larger Complexity Acceptable

        // Solution : To handle the contriant we are given that we have to cut them
        // in increasing order which provides us with solution itself

        // If gives tress are [ 10 , 12 , 11 ]
        // if i cut 10 next i have to cut will be 11 and i need to find a way to reach 11 
        // if possible find steps to it if not return -1
        vector<vector<int>> trees;
        for(int i=0; i<forest.size(); i++) {
            for(int j=0; j<forest[0].size(); j++) {
                if(forest[i][j] > 1) {
                    trees.push_back({forest[i][j], i, j});
                }
            }
        }

        // sorting the trees according to their height
        sort(trees.begin(), trees.end());

        //start points
        int sr=0, sc=0;
        int ans = 0;

        //cut trees in order
        for(int i=0; i<trees.size(); i++) {

            int cost = bfs(forest, sr,sc,trees[i][1], trees[i][2]);
            if(cost == -1) {
                return -1;
            }
            ans += cost;
            sr = trees[i][1];
            sc = trees[i][2];
        }

        return ans;
    }

    int bfs(vector<vector<int>>& forest, int sr, int sc, int tr, int tc) {
        if(sr == tr && sc == tc) {
            return 0;
        }

        queue<pair<int,int>> q;
        q.push({sr,sc});
        int m = forest.size(); int n = forest[0].size();
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};
        int cost = 0;
        seen[sr][sc] = true;
        while(!q.empty()) {
            int qsize = q.size();
            //go level wise
            for(int i=0; i<qsize; i++) {
                pair<int,int> point = q.front();
                q.pop();

                for(int j=0; j<4; j++) {
                    long int nr = point.first+dr[j];
                    long int nc = point.second+dc[j];
                    if(nr < 0 || nr>=m || nc<0 || nc>=n)
                        continue;
                    
                    //if new point now obstacle or seen then visit
                    if(!seen[nr][nc] && forest[nr][nc] != 0) {
                        q.push({nr,nc});
                        seen[nr][nc] = true;
                        // if target reached then return
                        if(nr == tr && nc==tc) {
                            return 1+cost;
                        }
                    }
                }
            }
            ++cost; //level complete increase cost
        }

        return -1;
    }
};
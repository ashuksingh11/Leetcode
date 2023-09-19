//79. Word Search
//https://leetcode.com/problems/word-search/description/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    bool dfs(int i, int j, int idx, string &s, vector<vector<int>> &vis, vector<vector<char>> &board)
    {
        if (idx == s.size())
            return true;

        vis[i][j] = 1;

        auto isvalid = [&](int i, int j)
        {
            return i >= 0 and j >= 0 and i < vis.size() and j < vis[0].size();
        };

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];

            if (isvalid(x, y) and !vis[x][y] and s[idx] == board[x][y])
                if (dfs(x, y, idx + 1, s, vis, board))
                    return true;
        }

        return vis[i][j] = 0;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<int>> vis(board.size(), vector<int>(board[0].size()));
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] == word[0])
                    if (dfs(i, j, 1, word, vis, board))
                        return true;
        return false;
    }
};
//1128. Number of Equivalent Domino Pairs
//https://leetcode.com/problems/number-of-equivalent-domino-pairs/description/
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>, int> um;
        int res = 0;
        
        for(auto d:dominoes) {
            if(d[0] > d[1]) {
                swap(d[0], d[1]);
            }
            
            res += um[make_pair(d[0],d[1])]++;//same as n*n-1/2
        }
        
        return res;
    }
};
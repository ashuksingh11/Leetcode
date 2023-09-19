//740. Delete and Earn
//https://leetcode.com/problems/delete-and-earn/description/

class Solution {
public:
    unordered_map<int, int> points;
    unordered_map<int,int> memo;

    int dp(int num) {
        if(num == 0) {
            return 0;
        }

        if(num == 1) {
            if(points.find(num) != points.end()) {
                return points[num];
            }
            else {
                return 0;
            }
        }

        if(memo.find(num) != memo.end()) {
            return memo[num];
        }

        int gain;
        if(points.find(num) != points.end()) {
            gain = points[num];
        }
        else {
            gain = 0;
        }

        memo[num] = max(dp(num-1), dp(num-2)+gain);

        return memo[num];
    }

    int deleteAndEarn(vector<int>& nums) {
        int maxnum = 0;
        for(int num: nums) {
            points[num] += num;
            maxnum = max(maxnum, num);
        }

        return dp(maxnum);
    }
};


///// bottom up

    class Solution {
    public:
        unordered_map<int, int> points;
        unordered_map<int,int> memo;

        int deleteAndEarn(vector<int>& nums) {
            int maxnum = 0;
            for(int num: nums) {
                points[num] += num;
                maxnum = max(maxnum, num);
            }

            vector<int> dp(maxnum+1, 0);
            if(points.find(1) != points.end()) {
                dp[1] = points[1];
            }
            else {
                dp[1] = 0;
            }

            for(int num=2; num<dp.size(); num++) {
                int gain =0;
                if(points.find(num) != points.end()) {
                    gain = points[num];
                }
                dp[num] = max(dp[num-1], gain+dp[num-2]);
            }

            return dp[maxnum];
        }
    };

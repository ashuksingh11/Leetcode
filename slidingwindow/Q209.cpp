//https://leetcode.com/problems/minimum-size-subarray-sum/submissions/?envType=study-plan-v2&envId=top-interview-150
//209. Minimum Size Subarray Sum

//brute force
// do an exhaustive search
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        int ans = INT_MAX;
        for(int i=0; i<size; i++) {
            for(int j=i; j<size; j++) {
                int sum = 0;
                for(int k=i; k<=j; k++) {
                    sum += nums[i];
                    if(sum >= target) {
                        ans = min(ans, j-i+1);
                    }
                }
            }
        }

        return ans==INT_MAX ? 0 : ans;
    }
};

////////////Brute force optimzed O(n^2)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        if(0==size) {
            return 0;
        }
        vector<int> sums(size);
        sums[0] = nums[0];
        int ans = INT_MAX;
        for(int i=1; i<size; i++) {
            sums[i] = sums[i-1] + nums[i];
        }
        for(int i=0; i<size; i++) {
            for(int j=i; j<size; j++) {
                int sum = sums[j] - sums[i] + nums[i];
                if(sum >= target) {
                    ans = min(ans, j-i+1);
                    break; // no need to check further
                }
            }
        }

        return ans==INT_MAX?0:ans;
    }
};


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //sliding window exapnd window till it reaches the target 
        // then minimize window by shrinking from left
        int start=0, sum =0;
        int windowlen = INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];

            while(sum >= target){
                windowlen = min(windowlen, i-start+1);

                sum = sum - nums[start];
                start++;
            }
        }

        if(windowlen == INT_MAX) {
            return 0;
        }
        else {
            return windowlen;
        }
    }
};
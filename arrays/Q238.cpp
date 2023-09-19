//238. Product of Array Except Self
//https://leetcode.com/problems/product-of-array-except-self/?envType=study-plan-v2&envId=top-interview-150
//https://leetcode.com/problems/product-of-array-except-self/solutions/1342916/3-minute-read-mimicking-an-interview/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // find product of left and right side of arrays or prefix.suffix
        int s = nums.size();
        vector<int> leftp(s);
        vector<int> rightp(s);
        vector<int> answer(s);
        leftp[0] = 1; rightp[s-1] = 1;

        for(int i=1; i<s; i++) {
            leftp[i] = leftp[i-1] * nums[i-1];
        }

        for(int i=s-2; i>=0; i--) {
            rightp[i] = rightp[i+1] * nums[i+1];
        }

        for(int i=0; i<s; i++) {
            answer[i] = leftp[i] * rightp[i];
        }

        return answer;
    }
};

//Optimized
// just use left product and right product appraoch but optimize by using res array itself
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();

        vector<int> res(size);
        res[0] = 1;

        for(int i=1; i<size; i++) {
            res[i] = res[i-1] * nums[i-1];
        }

        // 
        int R = 1;
        for(int i=size-1; i>=0; i--) {
            res[i] = res[i] * R;
            R = R*nums[i];
        }        

        return res;
    }
};

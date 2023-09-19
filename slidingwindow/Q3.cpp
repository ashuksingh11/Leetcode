//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/?envType=study-plan-v2&envId=top-interview-150
// 3. Longest Substring Without Repeating Characters

//use sliding window and maintain map of char with count
// if char found then move window from left till we exclude O(2n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        unordered_map<char, int> chars;
        int left=0,right=0;

        int res =0;
        while (right < size) {
            char r = s[right];
            chars[r]++;

            while(chars[r] > 1) {
                char l = s[left];
                chars[l]--;
                left++;
            }

            res = max (res, right-left+1);
            right++;
        }

        return res;
    }
};


//this is O(n) instead of storing count in map we store the index+1 (say j')
// now whenever duplicate is found then we move ahead j'+1
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        unordered_map<char, int> um;
        int i =0, res=0;
        for(int j=0; j<size; j++) {
            if(um[s[j]] > 0) {
                i = max(i, um[s[j]]);
            }
            res = max(res, j-i+1);

            um[s[j]] = j+1;

        }

        return res;
    }
};
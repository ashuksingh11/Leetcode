//https://leetcode.com/problems/valid-anagram/description/?envType=study-plan-v2&envId=top-interview-150
//242. Valid Anagram

// Input: s = "anagram", t = "nagaram"
// Output: true
// Input: s = "rat", t = "car"
// Output: false
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> countmap;

        for(auto c:s){
            countmap[c]++;
        }

        for(auto c:t) {
            countmap[c]--;
        }

        for(auto it:countmap) {
            if(it.second != 0) {
                return false;
            }
        }

        return true;
    }
};
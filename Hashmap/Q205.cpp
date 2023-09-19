//https://leetcode.com/problems/isomorphic-strings/?envType=study-plan-v2&envId=top-interview-150
//205. Isomorphic Strings
// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // use 2 hashmaps to check 1-to-1 correspondance
        unordered_map<char, char> mp1,mp2;

        for(int i=0; i<s.size(); i++) {
            if(mp1.find(s[i]) != mp1.end()) {
                if(mp1[s[i]] != t[i]) {
                    return false;
                }
            }
            if(mp2.find(t[i]) != mp2.end()) {
                if(mp2[t[i]] != s[i]) {
                    return false;
                }
            }

            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];            
        }

        return true;
    }
};
//https://leetcode.com/problems/ransom-note/description/?envType=study-plan-v2&envId=top-interview-150
//383. Ransom Note
// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

// Each letter in magazine can only be used once in ransomNote.

 

// Example 1:

// Input: ransomNote = "a", magazine = "b"
// Output: false
// Example 2:

// Input: ransomNote = "aa", magazine = "ab"
// Output: false
// Example 3:

// Input: ransomNote = "aa", magazine = "aab"
// Output: true

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //use map to store char and its occurence 
        unordered_map<char,int> hmap;
        for(auto c:magazine) {
            hmap[c]++;
        }

        for(auto c:ransomNote) {
            if(hmap[c] > 0) {
                hmap[c]--;
            }
            else {
                return false;
            }
        }

        return true;
    }
};
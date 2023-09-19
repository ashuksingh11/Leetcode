//https://leetcode.com/problems/group-anagrams/submissions/?envType=study-plan-v2&envId=top-interview-150
//49. Group Anagrams

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// sol by sorting the word and making it as key
// sorting of anagram will always result in same key thus simplifying sol
//O(mklogk)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;

        for(auto str : strs) {
            string unsortedstr = str;
            sort(str.begin(), str.end());
            um[str].push_back(unsortedstr);
        }

        vector<vector<string>> ans;
        for(auto it : um) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

//O(mk)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;

        for(auto str : strs) {
            string unsortedstr = str;
            countSort(str);
            um[str].push_back(unsortedstr);
        }

        vector<vector<string>> ans;
        for(auto it : um) {
            ans.push_back(it.second);
        }

        return ans;
    }

    // returns sorted key using count sort
    void countSort(string& str) {
        char count[26] = {0};
        for(auto c : str) {
            count[c-'a']++;
        }

        str = "";
        for(int i=0; i<26; i++) {
            str += string(count[i], i+'a');
        }
    }
};
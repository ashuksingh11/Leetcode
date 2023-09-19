//https://leetcode.com/problems/word-pattern/description/?envType=study-plan-v2&envId=top-interview-150
//290. Word Pattern
// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true
// Input: pattern = "abba", s = "dog cat cat fish"
// Output: false

//1. break and store words in vector
//2. map 1-to-1 and check pattern

class Solution {
public:
    bool wordPattern(string pat, string s) {
        vector<string> words;
        
        int i=0;
        string temp="";
        while(i<s.size())
        {
            if(s[i]==' ')
            {
                if(temp!="")
                words.push_back(temp);
                temp="";
            }
            else
            temp+=s[i];
            i++;
        }
        if(temp!="")
        words.push_back(temp);

        unordered_map<char, string> mp;
        unordered_map<string, char> mp2;

        int n=pat.size();
        if(n!=words.size()) return false;

        for(int i=0;i<n;i++)
        {
            if(mp.find(pat[i])==mp.end() and mp2.find(words[i])==mp2.end())
            {
                mp[pat[i]] = words[i];
                mp2[words[i]] = pat[i];
            }
            else if(mp[pat[i]]==words[i] and mp2[words[i]]==pat[i])
            continue;
            else return false;
        }
        return true;

    }
};
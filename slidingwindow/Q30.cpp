//30. Substring with Concatenation of All Words
//https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    int n;
    int wordlen;
    int substringsize;
    int k;
    unordered_map<string, int> wordmap;

    vector<int> findSubstring(string s, vector<string>& words) {
        n = s.size();
        wordlen = words[0].size();
        k = words.size();
        substringsize = k * wordlen;

        for(auto word:words) {
            wordmap[word]++;
        }

        vector<int> ans;
        for(int i=0; i<wordlen; i++) {
            slidingWindow(i, s, ans);
        }

        return ans;
    }

    void slidingWindow(int left, string& s, vector<int>& ans) {
        unordered_map<string,int> wordfound;
        int wordused = 0;

        //iterate
        // word_length at a time, and at each iteration we focus on one word
        for(int right = left; right <= n-wordlen; right += wordlen) {
            string sub = s.substr(right,wordlen);
            if(wordmap.count(sub) == 0) {
                wordfound.clear();
                wordused = 0;
                left = right+wordlen;
            }
            else {
                wordfound[sub]++;
                wordused++;
                while(wordfound[sub] > wordmap[sub]) {
                    string removeword = s.substr(left,wordlen);
                    wordfound[removeword]--;
                    left += wordlen;
                    --wordused;
                }
            }

            if(wordused == k) {
                ans.push_back(left);
            }
        }
    }
};
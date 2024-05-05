class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        int i=0,j=0;
        string out;
        while(i<m || j<n) {
            if(i<m) {
                out.push_back(word1[i++]);
            }
            if(j<n) {
                out.push_back(word2[j++]);
            }
        }

        return out;
    }
};
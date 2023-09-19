//https://leetcode.com/problems/h-index/?envType=study-plan-v2&envId=top-interview-150
//274. H-Index
// Approach 1 : 
// Main intuition , if we plot citations vs papers (in descending order)
// then if citations[i] > i then we have i+1 papers with atleast i+1 citations i.e. h index
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());

        int i =0;
        int s = citations.size();
        while(i < s && citations[s-1-i] > i) {
            i++;
        }

        //after while loop i = i'+1
        return i;
    }
};
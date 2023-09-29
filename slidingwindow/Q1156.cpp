//1156. Swap For Longest Repeated Character Substring
//https://leetcode.com/problems/swap-for-longest-repeated-character-substring/description/

// count continous char in window which is separated by 
// single char then take max of it , start again with new window
class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size(), i=0, maxj=0;
        
        unordered_map<char, int> um;
        for(auto c:text) {
            um[c]++;
        }
        
        if(um.size() == 1) {
            return n;
        }
        
        
        while(i<n) {
            int count_left = 1;
            while(i < n-1 && text[i] == text[i+1]) {
                count_left++;
                i++;
            }
            
            char ch = text[i];
            int j=i+2, count_right = 0, total_count = 0;
            
            while(j<n && ch == text[j]) {
                j++;
                count_right++;
            }
            
            total_count = count_left + count_right;
            if(um[ch] > total_count) {
                // we have more chars separated by single char which we can replace
                // by swapping
                maxj = max(maxj, total_count+1);
            }
            else {
                maxj = max(maxj, total_count);
            }
            ++i;
        }
        
        return maxj;
    }
};
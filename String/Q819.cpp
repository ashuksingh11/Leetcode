//819. Most Common Word
//https://leetcode.com/problems/most-common-word/description/
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> um;
        string temp = "";
        int maxc = 0;
        
        int n=paragraph.size();
        for(int i=0; i<n; i++) {
            char ch = tolower(paragraph[i]);
            
            if(ch>= 'a' && ch<= 'z') {
                temp += ch;
            }
            else {
                if(temp != "") {
                    um[temp]++;
                }
                temp = "";
            }
        }
        
        if(temp != "") {
            um[temp]++;
        }
        
        for(auto str:banned) {
            um.erase(str);
        }
        
        for(auto it:um) {
            if(it.second > maxc) {
                maxc = it.second;
                temp = it.first;
            }
        }
        
        return temp;
    }
};
//https://leetcode.com/problems/rotate-string/description/
//796. Rotate String

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) {
            return false;
        }
        
        string ns = s+s;
        int n = s.size();
        for(int i=0; i<n; i++) {
            string temp = ns.substr(i,n);
            if(temp == goal) {
                return true;
            }
        }
        
        return false;
    }
};
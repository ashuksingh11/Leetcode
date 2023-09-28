//https://leetcode.com/problems/remove-k-digits/description/
class Solution {
public:
    string removeKdigits(string num, int k) {
        //d1d2d3d4....dn, if d2<d1 remove d1
        stack<char> st;

        for(auto ch: num) {
            while(!st.empty() && k > 0 && st.top() > ch) {
                st.pop();
                --k;
            }
            //push except trailing zero
            if(!st.empty() || ch != '0') {
                st.push(ch); 
            }
            
        }

        while(!st.empty() && k>0) {
            st.pop();
            --k;
        }

        if(st.empty()) {
            return "0";
        }
        string ans = "";
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;


    }
};
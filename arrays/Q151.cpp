//https://leetcode.com/problems/reverse-words-in-a-string/?envType=study-plan-v2&envId=top-interview-150
//151. Reverse Words in a String
// Input: s = "the sky is blue"
// Output: "blue is sky the"

class Solution {
public:
    string reverseWords(string s) {
        
        stack<string> st;
        string temp ="";
        bool foundword = false;

        for(int i=0; i<s.size(); i++) {
            if (s[i] == ' ') {
                if(temp.size() > 0) {
                    st.push(temp);
                    temp = "";
                }
            }
            else {
                temp += s[i];
            }
        }

        if(temp.size() > 0) {
            st.push(temp);
        }

        string res="";
        while(!st.empty()) {
            res += st.top() + ' ';
            st.pop();
        }

        res.pop_back();

        return res;
    }
};
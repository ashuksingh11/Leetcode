//43. Multiply Strings
//https://leetcode.com/problems/multiply-strings/description/

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") {
            return "0";
        }
        
        int n1 = num1.size();
        int n2 = num2.size();
        
        string res(n1+n2,'0');
        
        for(int i=n1-1; i>=0; i--) {
            for(int j=n2-1; j>=0; j--) {
                int d = (num1[i]-'0') * (num2[j]-'0') + (res[i+j+1]-'0');
                res[i+j+1] = d%10 + '0';
                res[i+j] += d/10;
            }
        }
        
        //remove any trailing 0's
        for(int i=0; i<res.size(); i++) {
            if(res[i]!='0') 
                return res.substr(i);
        }
        
        return "0";
    }
};
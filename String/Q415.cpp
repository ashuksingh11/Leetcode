//415. Add Strings
//https://leetcode.com/problems/add-strings/description/

class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1[0]=='0' && num2[0]=='0')
            return "0";
        
        int i=num1.size()-1;
        int j=num2.size()-1;
        string res(max(num1.size(),num2.size())+1,'0');
        int k = max(num1.size(),num2.size());
        
        int carry = 0;
        
        while(i>=0 || j>=0 || carry>0) {
            int d1 = i>=0 ? num1[i]-'0':0;
            int d2 = j>=0 ? num2[j]-'0':0;
            //cout<<d1<<d2<<endl;
            
            int sum = d1+d2+carry;
            carry = sum/10;
            sum = sum%10;
            res[k] = sum+'0';
            --i,--j,--k;
        }
        
        i=0;
        while(res[i] == '0') {
            ++i;
        }
        
        return res.substr(i);
    }
};
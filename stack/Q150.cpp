//https://leetcode.com/problems/evaluate-reverse-polish-notation/description/?envType=study-plan-v2&envId=top-interview-150
//150. Evaluate Reverse Polish Notation

// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9

class Solution {
    bool isOp(string c){
        return c == "+" || c == "-" || c == "*" || c == "/";
    }
    
    int calc(int a, string c, int b){
        if(c == "+") return a + b;
        if(c == "-") return a - b;
        if(c == "*") return a * b;
        if(c == "/") return a / b;
        return 0; 
    }  
    
public:
    int evalRPN(vector<string>& tokens) {
        //stack<string> op;
        stack<int> num;
        
        for(auto i : tokens){
            if(isOp(i)){
                int n1 = num.top();
                num.pop();
                int n2 = num.top();
                num.pop();
                num.push(calc(n2, i, n1));
            }
            else{
                num.push(stoi(i));
            }
        }
        
        return num.top();
    }
};
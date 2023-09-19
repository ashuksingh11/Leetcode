//https://leetcode.com/problems/simplify-path/?envType=study-plan-v2&envId=top-interview-150
//71. Simplify Path
// By looking at examples we can see that the above simplification process just behaves like a stack.
// Whenever we encounter any file’s name, we simply push it into the stack.
// when we come across ” . ” we do nothing
// When we find “..” in our path, we simply pop the topmost element as we have to jump back to parent’s directory.
// When we see multiple “////” we just ignore them as they are equivalent to one single “/”.
// After iterating through the whole string the elements remaining in the stack is our simplified absolute path.
class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string> st;
        string res;
        
        for(int i = 0;  i<path.size(); ++i)
        {
            if(path[i] == '/')    
                continue;
            string temp;
			// iterate till we doesn't traverse the whole string and doesn't encounter the last /
            while(i < path.size() && path[i] != '/')
            {
				// add path to temp string
                temp += path[i];
                ++i;
            }
            if(temp == ".")
                continue;
			// pop the top element from stack if exists
            else if(temp == "..")
            {
                if(!st.empty())
                    st.pop();
            }
            else
			// push the directory file name to stack
                st.push(temp);
        }
        
		// adding all the stack elements to res
        while(!st.empty())
        {
            res = "/" + st.top() + res;
            st.pop();
        }
        
		// if no directory or file is present
        if(res.size() == 0)
            return "/";
        
        return res;
    }
};
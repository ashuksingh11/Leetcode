//17. Letter Combinations of a Phone Number

class Solution {
public:
unordered_map<char,string> um = {{'2',"abc"}, {'3', "def"},
        {'4', "ghi"}, {'5', "jkl"}, {'6',"mno"}, {'7', "pqrs"}, {'8', "tuv"},
        {'9',"wxyz"}};
    vector<string> letterCombinations(string digits) {
        

        vector<string> ans;
        string path="";
        
        if(digits.size() == 0) {
            return ans;
        }

        backtrack(0, digits, path, ans);

        return ans;
    }

    void backtrack(int index, string& digits, string& path, vector<string>& ans) {
        if(path.size() == digits.size()) {
            ans.push_back(path);
            return;
        }

        string letters = um[digits[index]];
        for(int i=0; i<letters.size(); i++) {
            path.push_back(letters[i]);
            backtrack(index+1, digits, path, ans);
            path.pop_back();
        }
    }
};
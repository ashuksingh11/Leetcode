//https://leetcode.com/problems/roman-to-integer/?envType=study-plan-v2&envId=top-interview-150
//13. Roman to Integer
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> hmap {
            {'I', 1}, {'V',5},{'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000} 
        };

        int answer = 0;

        for(int i=0; i<s.size(); i++) {
            //if curr char-val is smaller than next then substract else just keep on a
            //adding
            if(i+1 < s.size() && hmap[s[i]] < hmap[s[i+1]] ) {
                answer = answer - hmap[s[i]];
            }
            else {
                answer = answer + hmap[s[i]];
            }
        }

        return answer;
    }
};
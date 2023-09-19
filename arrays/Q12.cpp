//https://leetcode.com/problems/integer-to-roman/?envType=study-plan-v2&envId=top-interview-150
//12. Integer to Roman

// Main intuition is to prepare map 
class Solution {
public:
    string intToRoman(int num) {
        vector<string> ones = {"","I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        vector<string> tens = {"","X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> hundreds = {"","C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> thousands = {"","M", "MM", "MMM"};

        string thns = thousands[num/1000];
        string hunds = hundreds[(num%1000)/100];
        string tns = tens[(num%100)/10];
        string ons = ones[(num%10)];

        string roman = thns+hunds+tns+ons;

        return roman;
    }
};
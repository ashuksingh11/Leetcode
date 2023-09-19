//https://leetcode.com/problems/longest-common-prefix/?envType=study-plan-v2&envId=top-interview-150
//14. Longest Common Prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp= "";

        sort(strs.begin(), strs.end()); //lexicogreaphical sort

        string first = strs[0]; string last = strs[strs.size()-1];

        for(int i=0; i<min(first.size(), last.size()); i++) {

            if(first[i] != last[i]) {
                return lcp;
            }
            else {
                lcp += first[i];
            }
        }

        return lcp;
    }
};

/// Trie version
class Solution {
public:

    class Trie {
        public:
        bool isEnd;
        unordered_map<char, Trie*> children;

        Trie() {
            isEnd = false;
        }

        void insert(string str) {
            if(str.empty()) {
                isEnd = true;
                return;
            }

            char c = str[0];
            if(children.find(c) == children.end()) {
                children[c] = new Trie();
            }

            children[c]->insert(str.substr(1));
        }

        int PrefixLenCheck() {
            if (children.size() !=1 || isEnd)
                return 0;

            for(auto it : children) {
                return 1 + it.second->PrefixLenCheck();
            }

            return 0;
        }
    };

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        Trie* trie = new Trie();
        for(auto str : strs) {
            trie->insert(str);
        }

        int l = trie->PrefixLenCheck();

        if(l == 0) {
            return "";
        }

        return strs[0].substr(0, l);
        
    }
};

// divide and conquer
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        return longestCommonPrefix(strs,0, strs.size()-1);
    }

    string longestCommonPrefix(vector<string>& strs, int l, int r) {
        if(l == r) {
            return strs[l];
        }
        else {
            int mid = (l+r)/2;
            string lcpleft = longestCommonPrefix(strs,l,mid);
            string lcpright = longestCommonPrefix(strs,mid+1,r);
            return commonprefix(lcpleft,lcpright);
        }

    }

    string commonprefix(string left, string right) {
        int mins = min(left.size(), right.size());
        for(int i=0; i<mins; i++) {
            if(left[i] != right[i]) {
                return left.substr(0,i);
            }
        }

        return left.substr(0, mins);
    }
};


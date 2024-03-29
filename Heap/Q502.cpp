//502. IPO
//https://leetcode.com/problems/ipo/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        int n = profits.size();
        vector<pair<int,int>> projects;
        for(int i=0; i<n; i++) {
            projects.push_back({capital[i], profits[i]});
        }

        sort(projects.begin(), projects.end());
        priority_queue<int> pq;
        int ptr = 0;
        for(int i=0; i<k; i++) {
            while(ptr<n && projects[ptr].first <= w) {
                pq.push(projects[ptr].second);
                ptr++;
            }

            if(pq.empty()) {
                break;
            }

            w += pq.top();
            pq.pop();
        }

        return w;
    }
};

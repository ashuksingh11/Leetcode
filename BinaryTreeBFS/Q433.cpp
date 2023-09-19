//433. Minimum Genetic Mutation
//https://leetcode.com/problems/minimum-genetic-mutation/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string> q;
        unordered_set<string> seen;
        q.push(startGene);
        seen.insert(startGene);

        int steps = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                string node = q.front();
                q.pop();

                if(node == endGene) {
                    return steps;
                }

                for(char c: "ACGT") {
                    for(int j=0; j<node.size(); j++) {
                        string neighbor = node;
                        neighbor[j] = c;

                        if(!seen.count(neighbor) && find(bank.begin(), bank.end(), neighbor) != bank.end()) {
                            q.push(neighbor);
                            seen.insert(neighbor);
                        }
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};

//https://leetcode.com/problems/gas-station/?envType=study-plan-v2&envId=top-interview-150
//134. Gas Station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Approach
        /* In the question given that
If there exists a solution, it is guaranteed to be unique
-This lines clearly tells us that we have unique or no solution exists

Here two cases are possible

if our total_gas is less than our total cost in that case we can't complete our journey ,so will return -1

Now if we have a unique solution that means single starting_point exists
To find that point we will keep track of my current_gas+=gas[i]-cost[i]
lets suppose at any index our current gas became negative so we can clearly 
say that till that index all the gas station between ith and starting point are bad, starting point as well.
So, this means we can start trying at next gas_station on the i+1 station
after going through the array in later entries, we don't need to loop back because we know a solution exists */

        int totalgas =0, totalcost=0;
        int currgas =0, startpoint =0;

        for(int i=0;i <gas.size(); i++) {
            totalgas += gas[i];
            totalcost += cost[i];

            currgas = currgas - cost[i] + gas[i];

            if(currgas < 0)
            {
                startpoint = i+1;
                currgas=0;
            }
        }

        if(totalgas < totalcost)
            return -1;
        else
            return startpoint;  
    }
};
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), fuel = 0, count = 0, start = 0;

        // As it is circular route, appending the lists to themselves once
        for(int i=0; i<n-1; i++) {
            gas.push_back(gas[i]);
            cost.push_back(cost[i]);
        }

        for(int i=0; i<2*n-1; i++) {
            // If n gas stations are visited, then return start
            if(count == n)
                return start;

            // Fill the gas and use the fuel
            fuel += (gas[i] - cost[i]);
            count++;

            // If fuel < 0, we have to start over from (i+1)th index
            if(fuel < 0) {
                fuel = 0;
                count = 0;
                start = i + 1;
            }        
        }

        // Return start only if n stations are visited
        return (count == n) ? start : -1;
    }
};
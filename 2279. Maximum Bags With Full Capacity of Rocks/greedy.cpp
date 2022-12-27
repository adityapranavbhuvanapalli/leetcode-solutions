class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int count = 0, n = capacity.size();

        // Remaining capacity
        for(int i=0; i<n; i++)
            capacity[i] -= rocks[i];

        // Sort remaining capacities in ascending order
        sort(capacity.begin(), capacity.end());

        // GREEDY ALGORITHM (Find the bags with least remaining capacity and fill them first)
        for(int i=0; i<n && additionalRocks > 0; i++) {
            additionalRocks -= capacity[i];
            count += (additionalRocks >= 0);
        }
        
        return count;
    }
};
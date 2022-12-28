class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int count = 0, n = capacity.size();

        // Min Heap
        priority_queue<int, vector<int>, greater<int>> pq;

        // Remaining capacity
        for(int i=0; i<n; i++) 
            pq.push(capacity[i] - rocks[i]);
        
        // GREEDY ALGORITHM (Find the bags with least remaining capacity and fill them first)        
        while(pq.size() && additionalRocks > 0) {
            additionalRocks -= pq.top();
            pq.pop();
            count += (additionalRocks >= 0);
        }

        return count;
    }
};
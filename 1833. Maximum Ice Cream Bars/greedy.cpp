class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int i, n = costs.size();

        // Pre-Sorting
        sort(costs.begin(), costs.end());

        for(i=0; i<n; i++) {
            coins -= costs[i];
            if(coins < 0)
                return i;
        }

        return n;
    }
};
class Solution {
public:
    map<pair<int, int>, int> dp;
    int maxProfit(vector<int>& prices, int fee) {
        return solve(0, prices.size(), 0, fee, prices);
    }

    int solve(int i, int n, int owned, int fee, vector<int>& prices) {
        if(i >= n)
            return 0;

        // Check if dp[i][owned] exists already
        if(dp.count({i, owned}))
            return dp[{i, owned}];

        int pick, notpick;

        if(owned) {
            // Sell or wait
            pick = prices[i] + solve(i+1, n, 1-owned, fee, prices);
            notpick = solve(i+1, n, owned, fee, prices);
        } else {
            // Buy or wait (Pay transaction fee if bought)
            pick = -prices[i] - fee + solve(i+1, n, 1-owned, fee, prices);
            notpick = solve(i+1, n, owned, fee, prices);
        }

        return dp[{i, owned}] = max(pick, notpick);
    }
};
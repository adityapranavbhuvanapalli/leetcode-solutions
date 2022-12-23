class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, n, 0, prices, dp);
    }

    int solve(int i, int n, int owned, vector<int>& prices,vector<vector<int>>& dp) {
        if(i >= n)
            return 0;

        if(dp[i][owned] != -1)
            return dp[i][owned];

        int pick, notpick;

        if(!owned) {
            // Then buy or wait
            pick = -prices[i] + solve(i+1, n, 1-owned, prices, dp); 
            notpick = solve(i+1, n, owned, prices, dp);
        } else {
            // Sell or wait
            // NOTE: After selling, need to wait for cooldown, hence i+2
            pick = prices[i] + solve(i+2, n, 1-owned, prices, dp);
            notpick = solve(i+1, n, owned, prices, dp);
        }

        return dp[i][owned] = max(pick, notpick);
    }
};
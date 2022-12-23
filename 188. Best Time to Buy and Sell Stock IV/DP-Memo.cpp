class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(0, n, 0, prices, k, dp);
    }

    int solve(int i, int n, int owned, vector<int>& prices, int remTxns, vector<vector<vector<int>>>& dp) {
        if(i >= n || remTxns == 0)
            return 0;
        
        if(dp[i][owned][remTxns] != -1)
            return dp[i][owned][remTxns];

        int pick, notpick;

        if(!owned) {
            // Buy or wait
            pick = -prices[i] + solve(i+1, n, 1-owned, prices, remTxns, dp);
            notpick = solve(i+1, n, owned, prices, remTxns, dp);
        } else {
            // Sell or wait
            pick = prices[i] + solve(i+1, n, 1-owned, prices, remTxns-1, dp);
            notpick = solve(i+1, n, owned, prices, remTxns, dp);
        }

        return dp[i][owned][remTxns] = max(pick, notpick);
    }
};
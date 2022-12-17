class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        int minVal;
        
        dp[1] = 1;        
        for(int i=2; i<=n; i++) {
            minVal = INT_MAX;

            for(int j=1; j*j<=i; j++)
                minVal = min(minVal, dp[i-(j*j)]);
            
            dp[i] = 1 + minVal;
        }

        return dp[n];
    }
};
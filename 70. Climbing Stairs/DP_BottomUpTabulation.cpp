class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp;
        dp.push_back(1);
        dp.push_back(2);
        for(int i=2; i<n;i++)
            dp.push_back(dp[i-2] + dp[i-1]);
        return dp[n-1];
    }
};
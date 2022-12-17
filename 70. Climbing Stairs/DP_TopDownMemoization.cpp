class Solution {
public:
    map<int, int> dp;
    int climbStairs(int n) {
        if(dp.count(n)==1)
            return dp[n];

        if(n==0 || n==1)
            return 1;

        return dp[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};
class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        return calc(n, dp);
    }
    
    int calc(int n, vector<int>& dp) {        
        if(n==0 || n==1)
            return n;
        if(n==2)
            return 1;
        
        if(dp[n]!=-1)
            return dp[n];
        
        dp[n] = calc(n-1, dp) + calc(n-2, dp) + calc(n-3, dp);
        return dp[n];
    }
};
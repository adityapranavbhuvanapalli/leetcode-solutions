class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool> dp(n, false);
        dp[0]=true;
        for(int i=0; i<n && !dp[n-1]; i++)
            if(dp[i])
                for(int j=0; j<=nums[i] && i+j<n; j++)
                    dp[i+j]=true;
        
        return dp[n-1];
    }
};
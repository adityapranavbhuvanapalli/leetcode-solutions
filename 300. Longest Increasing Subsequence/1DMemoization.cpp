class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return solve(0, n, -1, nums, dp);
    }

    int solve(int i, int n, int prev, vector<int>& nums, vector<int>& dp) {
        if(i >= n)
            return 0;

        if(dp[prev+1] != -1)
            return dp[prev+1];

        int pick = (prev == -1 || nums[prev] < nums[i]) ? 1 + solve(i+1, n, i, nums, dp) : 0;
        int notpick = solve(i+1, n, prev, nums, dp);

        return dp[prev+1] = max(pick, notpick);
    } 
};
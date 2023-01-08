class Solution {
public:
    int numDistinct(string s, string t) {
        int sLen = s.size(), tLen = t.size();
        vector<vector<int>> dp(sLen, vector<int>(tLen, -1));
        return solve(0, 0, sLen, tLen, s, t, dp);
    }

    int solve(int i, int j, int sLen, int tLen, string& s, string& t, vector<vector<int>>& dp) {
        if(j == tLen)
            return 1;

        if(i == sLen)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int pick, notpick;

        pick = (s[i] == t[j]) ? solve(i+1, j+1, sLen, tLen, s, t, dp) : 0;
        notpick = solve(i+1, j, sLen, tLen, s, t, dp);
    
        return dp[i][j] = pick + notpick;
    }
};
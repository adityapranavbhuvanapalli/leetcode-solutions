class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int left, top, diagonal;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                left = (j>0) ? dp[i][j-1] : 0;
                top = (i>0) ? dp[i-1][j] : 0;
                diagonal = (i>0 && j>0) ? dp[i-1][j-1] : 0;
                
                dp[i][j] = (text1[i] == text2[j]) ? (1 + diagonal) : max(left, top);
            }
        }

        return dp[m-1][n-1];
    }
};
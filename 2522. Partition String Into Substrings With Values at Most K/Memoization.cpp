class Solution {
public:
    int minimumPartition(string s, int k) {
        int n = s.size();
        vector<int> dp(n, -1);
        int res = (int)solve(0, n, s, k, dp);
        return res == INT_MAX ? -1 : res;
    }

    long solve(int start, int n, string& s, int k, vector<int>& dp) {
        if(start >= n)
            return 0;

        if(dp[start] != -1)
            return dp[start];

        int val = INT_MAX;

        for(int i=1; start+i <= n && i<=to_string(k).size(); i++) {
            if(stol(s.substr(start, i)) > k)
                break;
        
            val = min((long)val, long(1 + solve(start+i, n, s, k, dp)));
        }

        return dp[start] = val;
    }
};
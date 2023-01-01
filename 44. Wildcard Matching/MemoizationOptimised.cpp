class Solution {
public:
    map<pair<int, int>, int> dp;
    bool isMatch(string s, string p) {
        // If p is empty
        if(p == "")
            return s == "";
        
        // Remove redundant *'s from p e.g., a**b**c == a*b*c
        for(int i=0; i<p.size()-1; i++) {
            if(p[i] == '*' && p[i+1] == p[i]) {
                p.erase(p.begin() + i);
                i--;
            }
        }
              
        return solve(0, 0, s.size(), p.size(), s, p);
    }

    bool solve(int i, int j, int sLen, int pLen, string& s, string& p) {
        if(dp.count({i, j}) == 1)
            return dp[{i, j}];

        if(j == pLen)
            return dp[{i, j}] = (i == sLen);

        if(p[j] == '*') 
            return dp[{i, j}] = solve(i, j+1, sLen, pLen, s, p) 
                || (i<sLen && solve(i+1, j, sLen, pLen, s, p));
        
        return dp[{i, j}] = i<sLen 
            && (s[i] == p[j] || p[j] == '?') 
            && solve(i+1, j+1, sLen, pLen, s, p);
    }
};
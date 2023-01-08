class Solution {
public:
    map<vector<int>, bool> dp; 
    bool isInterleave(string p, string q, string pq) {
        int np = p.size(), nq = q.size(), n = pq.size();

        if(np + nq != n)
            return false;

        return solve(0, 0, 0, np, nq, n, p, q, pq);
    }

    bool solve(int i, int j, int k, int& np, int& nq, int& n, string& p, string& q, string& pq) {
        if(i == np && j == nq)
            return k == n;

        if(dp.count({k, i, j}) == 1)
            return dp[{k, i, j}];

        bool pickp = false, pickq = false;

        if(i < np && p[i] == pq[k]) 
            pickp = solve(i+1, j, k+1, np, nq, n, p, q, pq);

        if(j < nq && q[j] == pq[k]) 
            pickq = solve(i, j+1, k+1, np, nq, n, p, q, pq);

        return dp[{k, i, j}] = pickp || pickq;
    }
};
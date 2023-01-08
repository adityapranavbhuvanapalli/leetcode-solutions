class Solution {
public:
    vector<int> fact = {1, 1, 2, 6, 24, 120, 720, 5040, 5040*8, 5040*8*9};
    string getPermutation(int n, int k) {
        int q;
        
        // Form the first permutation
        string s = "", res = "";
        for(int i=1; i<=n; i++) 
            s += to_string(i);

        k--;
        while(k > 0) {
            q = k / fact[n-1];
            k = k % fact[n-1];
            res += s[q];
            s.erase(q, 1);
            n--;
        }

        return res + s;
    }
};
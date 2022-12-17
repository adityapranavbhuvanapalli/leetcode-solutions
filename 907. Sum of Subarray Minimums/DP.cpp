class Solution {
public:
    int mod = pow(10, 9) + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), res = 0, minIdx;
        vector<int> stack, dp(n, 0);
        for(int i=0; i<n; i++) {
            while(stack.size() && arr[stack.back()] >= arr[i])
                stack.pop_back();
            
            if(stack.size()) { 
                minIdx = stack.back();
                dp[i] = dp[minIdx] + (i - minIdx) * arr[i];
            } else 
                dp[i] = (i+1)*arr[i];
            res = (res + dp[i]) % mod;
            stack.push_back(i);
        }
            
        return res;
    }
};
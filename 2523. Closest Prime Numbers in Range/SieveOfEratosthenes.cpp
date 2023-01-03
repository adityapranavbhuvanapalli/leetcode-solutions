class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> isPrime(1e6 + 1, true), range, res{-1,-1};
        isPrime[0] = isPrime[1] = false;

        for(int i=2; i<=right; i++) {
            for(int j=2; i*j<=right; j++) {
                isPrime[i*j] = false;
            }
        }

        for(int i=left; i<=right; i++) {
            if(isPrime[i])
                range.push_back(i);
        }

        int n = range.size(), minDiff = INT_MAX, diff;

        for(int i=1; i<n; i++) {
            diff = range[i] - range[i-1];
            if(diff <= 2)
                return {range[i-1], range[i]};

            if(diff < minDiff) {
                minDiff = diff;
                res = {range[i-1], range[i]};
            }
        }

        return res;
    }
};
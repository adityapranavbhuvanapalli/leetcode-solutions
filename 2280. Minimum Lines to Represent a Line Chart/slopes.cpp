class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n = stockPrices.size(), count = 1;
        if(n == 1)
            return 0;
        
        sort(stockPrices.begin(), stockPrices.end());
        long double prevSlope = findSlope(stockPrices[0], stockPrices[1]), slope;

        for(int i=2; i<n; i++) {
            slope = findSlope(stockPrices[i-1], stockPrices[i]);
            count += (slope != prevSlope);
            prevSlope = slope;
        }

        return count;
    }

    // Function to find slope of 2 points
    long double findSlope(vector<int>& a, vector<int>& b) {
        return ((long double)(b[1] - a[1])) / ((long double)(b[0] - a[0]));
    }
};
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minVal = INT_MAX, n = matrix.size();
        int l, r, u;

        // Handle base case (For n = 1)
        if(n == 1) {
            for(auto& cell: matrix[0]) 
                minVal = min(minVal, cell);
            return minVal;
        }

        // Bottom Up Tabulation
        for(int i=1; i<n; i++) {
            for(int j=0; j<n; j++) {
                l = (j > 0) ? matrix[i-1][j-1] : INT_MAX;
                r = (j < n-1) ? matrix[i-1][j+1] : INT_MAX;
                u = matrix[i-1][j];

                matrix[i][j] += min({l, r, u});

                // Find min of last row
                if(i == n-1)
                    minVal = min(minVal, matrix[i][j]);
            }
        }

        return minVal;
    }
};
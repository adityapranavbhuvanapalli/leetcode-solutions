class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacle) {
        int m=obstacle.size(), n=obstacle[0].size();
        vector<vector<long>> ways(m, vector<long>(n, 0));
        
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                if(i==m-1 && j==n-1)
                    ways[i][j] = !obstacle[i][j];
                else if(i==m-1)
                    ways[i][j] = obstacle[i][j] ? 0 : ways[i][j+1];
                else if(j==n-1)
                    ways[i][j] = obstacle[i][j] ? 0 : ways[i+1][j];
                else
                    ways[i][j] = obstacle[i][j] ? 0 : ways[i+1][j] + ways[i][j+1];
            }
        }
        return (int)ways[0][0];
    }
};
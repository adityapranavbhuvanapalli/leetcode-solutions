class Solution {
public:
    int m, n;
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x0, y0, total = 0;

        m = grid.size(), n = grid[0].size();

        // Find start position and total no. of empty squares
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                // Find starting position
                if(grid[i][j] == 1)
                    x0 = i, y0 = j;
                    
                // Keep track of total no. of empty squares
                total += (grid[i][j] != -1);
            } 
        }

        return solve(x0, y0, 1, total, grid);
    }

    int solve(int x, int y, int count, int total, vector<vector<int>>& grid) {
        if(!inRange(x, y) || grid[x][y] == -1)
            return 0;

        if(grid[x][y] == 2) 
            return count == total;

        // Backtrack
        grid[x][y] = -1; // Marking as visited.

        int top = solve(x-1, y, count+1, total, grid);
        int bottom = solve(x+1, y, count+1, total, grid);
        int left = solve(x, y-1, count+1, total, grid);
        int right = solve(x, y+1, count+1, total, grid);

        grid[x][y] = 0; // Making it back as unvisited.

        return top + bottom + left + right;
    }

    bool inRange(int x, int y) {
        return x>=0 && x<m && y>=0 && y<n;
    }
};
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;
        vector<pair<int, int>> q;
        bool isClosed;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                isClosed = true;
                if(grid[i][j] != 0)
                    continue;
                
                // BFS
                q.push_back({i, j});
                grid[i][j] = -1;
                while(q.size()) {
                    auto [x, y] = q[0];

                    // If any part of the island is on the corners, it is not a closed island
                    if(x == 0 || x == m-1 || y == 0 || y == n-1)
                        isClosed = false;

                    if(x+1 < m && !grid[x+1][y])
                    q.push_back({x+1, y}), grid[x+1][y] = -1;
                    
                    if(x-1 >= 0 && !grid[x-1][y])
                        q.push_back({x-1, y}), grid[x-1][y] = -1;

                    if(y+1 < n && !grid[x][y+1])
                        q.push_back({x, y+1}), grid[x][y+1] = -1;
                    
                    if(y-1 >= 0 && !grid[x][y-1])
                        q.push_back({x, y-1}), grid[x][y-1] = -1;

                    q.erase(q.begin());
                }

                // Increment count if the island is closed
                count += isClosed;
            }
        }   

        return count;
    }
};


/*
* NOTE:
*   Whenever I am making grid[i][j] = -1, it means that I am marking it as VISITED, so I do not visit the same grid[i][j] again.
*   Instead of doing this, we can also use a boolean visited matrix to mark (i, j) as VISITED.
*   But the first method is BETTER in terms of space complexity as we don't have to use an extra matrix. 
*/ 
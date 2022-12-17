class Solution {
public:
    int m, n, x, y;
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m = maze.size(), n = maze[0].size();
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<tuple<int, int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> cur;
        
        q.push_back({entrance[0], entrance[1], 0});
        visited[entrance[0]][entrance[1]] = true;
        while(q.size()) {
            auto [x0, y0, steps] = q[0];

            if(x0 == 0 || y0 == 0 || x0 == m-1 || y0 == n-1)
                if(x0 != entrance[0] || y0 != entrance[1])
                    return steps;
            
            for(auto dir: dirs) {
                x = x0 + dir[0];
                y = y0 + dir[1];
                if(inRange(x, y) && !visited[x][y] && maze[x][y] == '.') {
                    visited[x][y] = true;
                    q.push_back({x, y, steps + 1});
                }
            }
            q.erase(q.begin());
        }

        return -1;
    }

    bool inRange(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
};
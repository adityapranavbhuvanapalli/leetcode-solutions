class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid[0].size(), left=-1, right=1, cur;
        vector<int> pos;

        // Initial Positions
        for(int i=0; i<n; i++)
            pos.push_back(i);
        
        // After processing each row, balls move to the next row
        for(auto row: grid) {
            for(int j=0; j<n; j++) {
                cur = pos[j]; // Current Position of the ball started at jth position
                if(cur == -1) // It means ball got stuck
                    continue;
                
                // Process the Directions based on the definition
                if(row[cur] == left)
                    pos[j] = (cur==0 || row[cur-1] == right) ? -1 : cur-1;
                else
                    pos[j] = (cur==n-1 || row[cur+1] == left) ? -1 : cur+1;
            }
        }
        return pos;
    }
};
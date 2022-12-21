class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(), cur, visitCount = 0;
        vector<bool> visited(n, false);
        vector<int> q;
        
        // BFS
        q.push_back(0);
        visited[0] = true;
        while(q.size()) {
            cur = q[0];
            q.erase(q.begin());

            // Keep track of no. of rooms visited 
            visitCount++;

            // Add the unlocked rooms to queue
            for(int& i: rooms[cur]) {
                if(!visited[i]) {
                    visited[i] = true;
                    q.push_back(i);
                }
            }
        }

        return visitCount == n;
    }
};
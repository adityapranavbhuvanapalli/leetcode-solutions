class Solution {
public:
    const int RED = 0, BLUE = 1;
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> res(n, -1);
        vector<vector<pair<int, int>>> graph(n);
        vector<vector<bool>> visited(n, vector<bool>(2, false));
        vector<vector<int>> q;  // queue(node, dist, color)

        // Make Adjacency Graph
        for(auto& edge: redEdges)
            graph[edge[0]].push_back({edge[1], RED});
        for(auto& edge: blueEdges)
            graph[edge[0]].push_back({edge[1], BLUE});

        // BFS
        q.push_back({0, 0, -1});
        while(q.size()) {
            int cur = q[0][0], dist = q[0][1], lastColor = q[0][2];
            q.erase(q.begin());

            if(res[cur] == -1)
                res[cur] = dist;

            // Add adjacent nodes with alternating color edges to q
            for(auto& [adj, color]: graph[cur]) {
                if(lastColor == -1 || (!visited[adj][color] && lastColor != color)) {
                    q.push_back({adj, dist+1, color});
                    visited[adj][color] = true;
                }
            }

        }

        return res;
    }
};
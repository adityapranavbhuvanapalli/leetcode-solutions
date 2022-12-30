class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<pair<int, vector<int>>> q;
        vector<vector<int>> paths;
        int dest = graph.size()-1;

        // BFS
        q.push_back({0, {}});
        while(q.size()) {
            // Get the front of the queue
            auto [src, path] = q[0];
            q.erase(q.begin());

            // Push src to path
            path.push_back(src);

            // If src reaches destination, add path to paths
            if(src == dest)
                paths.push_back(path);

            // Add all the adjacent nodes to src
            for(auto& adj: graph[src]) 
                q.push_back({adj, path});
        }

        return paths;
    }
};
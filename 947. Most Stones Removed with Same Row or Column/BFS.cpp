class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size(), count=0;
        map<int, vector<int>> graph;
        vector<int> visited(n, false);

        // Make Adjacency graph
        for (int i=0; i<n-1; i++) {
            for (int j=i+1; j<n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        for(int i=0; i<n; i++) {
            if(visited[i])
                continue;

            // BFS
            vector<int> q;
            q.push_back(i);
            visited[i] = true;
            while(q.size()) {
                // Find adjacent stones and push to queue
                int cur = q[0];
                for (auto neighbor: graph[cur]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push_back(neighbor);
                    }
                }
                q.erase(q.begin());
            }
            count++;
        }

        return n-count;
    }
};
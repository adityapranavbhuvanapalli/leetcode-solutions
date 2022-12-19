class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // If source and destinaton are same. (Because of bidirectional edges)
        if(source == destination)  
            return true;

        // If source and destination are different
        vector<vector<int>> graph(n);
        vector<int> q;
        vector<bool> visited(n, false);
        int cur;

        // Make Adjacency Graph
        for(auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Perform BFS Traversal
        q.push_back(source);
        visited[source] = true;
        while(q.size()) {
            cur = q[0];
            q.erase(q.begin());

            for(auto& adj: graph[cur]) {
                if(adj == destination)
                    return true;
                else if(!visited[adj]){
                    q.push_back(adj);
                    visited[adj] = true;
                }
            }
        }

        // If traversal is completed but destination is not found
        return false;
    }
};
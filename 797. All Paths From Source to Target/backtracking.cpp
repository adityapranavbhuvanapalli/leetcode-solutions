class Solution {
public:
    typedef vector<vector<int>> VectorInt2D; 
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        VectorInt2D paths;
        backtrack(0, graph.size()-1, graph, paths, {});
        return paths;
    }

    void backtrack(int src, int dest, VectorInt2D& graph, VectorInt2D& paths, vector<int> path) {
        if(src == dest) {
            path.push_back(dest);
            paths.push_back(path);
            return;
        }

        // Backtracking
        path.push_back(src);
        for(auto& adj: graph[src])
            backtrack(adj, dest, graph, paths, path);
        path.pop_back();
    }
};
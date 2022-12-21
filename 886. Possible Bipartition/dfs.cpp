class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> groups(n+1, -1);
        vector<vector<int>> graph(n+1);

        // Make adjacency graph
        for(auto& edge: dislikes) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for(int i=1; i<=n; i++)
            if(groups[i] == -1 && !dfs(i, 0, groups, graph))
                return false;
        
        return true;
    }

    bool dfs(int node, int grp, vector<int>& groups, vector<vector<int>>& graph) {
        if(groups[node] != -1)
            return groups[node] == grp;
        
        groups[node] = grp;
        
        for(auto& i: graph[node])
            if(!dfs(i, 1-grp, groups, graph))
                return false;
        
        return true;
    }
};
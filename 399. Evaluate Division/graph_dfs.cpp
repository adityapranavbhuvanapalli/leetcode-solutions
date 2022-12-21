class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        unordered_map<string, unordered_map<string, double>> graph; // (num, (den, val))
        int n = equations.size();

        // Make adjacency graph 
        /* NOTE: 
            * IT IS NOT BI-DIRECTIONAL GRAPH 
            * Because a/b != b/a
        */
        for(int i=0; i<n; i++) {
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1/values[i];
        }

        // Find result for each query
        for(auto& query: queries) {
            set<string> visited;
            res.push_back(dfs(query[0], query[1], graph, visited));
        }

        return res;
    }

    double dfs(string src, string dest, unordered_map<string, unordered_map<string, double>>& graph, set<string>& visited) {
        // If numerator or denominator is not in graph, return -1
        if(graph.count(src) == 0 || graph.count(dest) == 0)
            return -1;
        
        // If the result is already there, return the result
        if(graph[src].count(dest))
            return graph[src][dest];

        // If src/dest is not there, 
        // Perform src/x * x/dest where x indicates each adjacent unvisited node of src
        double div;
        for(auto& [x, val]: graph[src]) {
            // Perform division only if x is unvisited
            if(visited.insert(x).second) {
                // Find x/dest
                div = dfs(x, dest, graph, visited);

                // Return the result only if it is not -1
                if(div >= 0)
                    return (val * div);
            }
        }

        return -1;
    }
};
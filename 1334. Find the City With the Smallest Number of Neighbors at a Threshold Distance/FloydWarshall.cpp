class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> graph(n, vector<int>(n, INT_MAX/2));
        int minCount = INT_MAX, minCountCity = -1, count;

        // Make Adjacency graph
        for(int i=0; i<n; i++)
            graph[i][i] = 0;

        for(auto& edge: edges) {
            graph[edge[0]][edge[1]] = edge[2];
            graph[edge[1]][edge[0]] = edge[2];
        }

        // Floyd-Warshall
        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

        // Find the city with least count wrt distanceThreshold
        for(int i=0; i<n; i++) {
            count = 0;
            for(auto& row: graph[i])
                if(row <= distanceThreshold)
                    count++;
            
            if(count <= minCount) {
                minCount = count;
                minCountCity = i;
            }
        }

        return minCountCity;
    }
};
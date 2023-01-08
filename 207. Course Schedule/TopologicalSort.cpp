class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<bool> completed(numCourses, false);

        // Make Adjacency Graph
        for(auto& edge: prerequisites)
            graph[edge[0]].push_back(edge[1]);

        for(int i=0; i<numCourses; i++) {
            // Find node with 0 prerequisites
            int top=-1;
            for(int i=0; i<numCourses; i++) {
                if(!completed[i]) {
                    int undonePres = 0;
                    for(auto& pre: graph[i]) {
                        undonePres += !completed[pre];
                    }
                    if(undonePres == 0) {
                        top = i;
                        break;
                    }
                }
            }
            
            if(top == -1)
                return false;

            // Complete top
            completed[top] = true;
        }

        return true;
    }
};


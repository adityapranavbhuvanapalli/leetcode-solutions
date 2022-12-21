class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, int> importance;               // MAP(empId, importance)
        unordered_map<int, vector<int>>  subordinates;    // MAP(empId, subordinates)
        int cur, totalImp = 0;
        vector<int> q;

        // Make 2 hashtables
        for(auto& emp: employees) {
            importance[emp->id] = emp->importance;
            subordinates[emp->id] = emp->subordinates;
        }

        // BFS
        q.push_back(id);
        while(q.size()) {
            cur = q[0];

            // Add the importance of front
            totalImp += importance[cur];

            // Add the subordinates of front to queue
            for(auto& sub: subordinates[cur])
                q.push_back(sub);

            q.erase(q.begin());
        }
        
        return totalImp;
    }
};
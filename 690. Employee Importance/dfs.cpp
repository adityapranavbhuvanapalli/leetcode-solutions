class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, int> importance;               // MAP(empId, importance)
        unordered_map<int, vector<int>> subordinates;     // MAP(empId, subordinates)

        // Make 2 hashtables
        for(auto& emp: employees) {
            importance[emp->id] = emp->importance;
            subordinates[emp->id] = emp->subordinates;
        }

        return dfs(id, importance, subordinates);
    }

    int dfs(int id, unordered_map<int, int>& importance, unordered_map<int, vector<int>>& subordinates) {
        int totalImp = importance[id];

        for(auto& sub: subordinates[id])
            totalImp += dfs(sub, importance, subordinates);

        return totalImp;
    }
};
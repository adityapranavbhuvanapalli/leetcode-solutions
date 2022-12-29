class Solution {

typedef pair<int, int> Pair; //pair(processingTime, index)
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
        vector<int> res;
        long n = tasks.size(), time = 0, i = 0;

        // Add indices to tasks
        for(int i=0; i<n; i++)
            tasks[i].push_back(i);

        // Sort the tasks wrt enqueue time
        sort(tasks.begin(), tasks.end(), [](auto& l, auto& r){
            return l[0]!=r[0] ? l[0]<r[0] : l[1]<r[1];
        });
    
        while(i<n || pq.size()) {
            if(!pq.size())
                time = max(time, (long)tasks[i][0]);

            // Push all tasks to pq less than time
            while(i<n && tasks[i][0] <= time) {
                pq.push({tasks[i][1], tasks[i][2]});    
                i++;
            }

            // Select the task with min processing time
            auto [processingTime, idx] = pq.top();
            pq.pop();
            time += processingTime;
            res.push_back(idx);    
        }

        return res;
    }
};
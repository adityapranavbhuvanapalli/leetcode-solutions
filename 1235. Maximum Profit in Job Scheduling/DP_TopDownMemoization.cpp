class Solution {
public:
    map<int, int> dp;
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        vector<vector<int>> jobs;
        for(int i=0; i<n; i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        
        sort(jobs.begin(), jobs.end());
        return calc(0, jobs, n);
    }

    int calc(int i, vector<vector<int>>& jobs, int n){
        if(i == n)
            return 0;

        if(dp.count(i) == 1) 
            return dp[i];

        int start = jobs[i][0], end = jobs[i][1], profit = jobs[i][2];
        
        // Find next job if i is included
        int next = i+1;
        while(next<n && jobs[next][0] < end)
            next++;

        // Include i or do not include i
        return dp[i] = max(calc(i+1, jobs, n), profit + calc(next, jobs, n));
    }
};
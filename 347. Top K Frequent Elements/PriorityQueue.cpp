class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> M;
        vector<int> res;
        priority_queue<pair<int, int>> pq;

        for(auto& num: nums)
            M[num]++;

        for(auto& [k, v]: M)
            pq.push({v, k});
        
        while(k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
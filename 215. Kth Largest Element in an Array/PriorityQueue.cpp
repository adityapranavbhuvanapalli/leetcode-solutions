class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int res;
        priority_queue<int> pq; // Max Heap
        
        for(auto& num: nums)
            pq.push(num);

        while(k--) {
            res = pq.top();
            pq.pop();
        }

        return res;
    }
};
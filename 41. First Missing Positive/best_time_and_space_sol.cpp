class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0, n = nums.size(), t;
        while(i<n) {
            if(nums[i] == i+1 || !(nums[i] > 0 && nums[i] < n) || nums[i] == nums[nums[i] - 1])
                i++;
            else
                swap(nums[i], nums[nums[i] - 1]);
        }

        for(int i=0; i<n; i++) 
            if(nums[i] != i+1)
                return i+1;
        
        return n+1;
    }
};

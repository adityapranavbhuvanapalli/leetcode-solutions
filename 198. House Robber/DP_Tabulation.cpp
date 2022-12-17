class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), pick, notpick;

        for(int i=n-2; i>=0; i--) {
            pick = nums[i] + ( i+2<n ? nums[i+2] : 0);
            notpick = nums[i+1];
            nums[i] = max(pick, notpick);
        }
        
        return nums[0];
    }
};
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long lSum = 0, rSum = 0;
        long minVal = LONG_MAX, minIdx = 0; 
        long mad, lastIdxMad;

        for(auto& num: nums)
            rSum += num;

        lastIdxMad = rSum/n;

        for(int i=0; i<n-1; i++) {
            lSum += nums[i];
            rSum -= nums[i];

            mad = abs(lSum/(i+1) - rSum/(n-i-1));
            if(mad < minVal) {
                minVal = mad;
                minIdx = i;
            }
        }

        return (lastIdxMad < minVal) ? n-1 : minIdx;
    }
};
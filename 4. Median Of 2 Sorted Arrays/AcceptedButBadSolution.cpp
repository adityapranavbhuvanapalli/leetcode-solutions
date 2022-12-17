class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int i=0, j=0, k=0;
        int m=nums1.size(), n=nums2.size(), dat, x=m+n;
        while(i<m && j<n) {
            if(nums1[i]<nums2[j]){
                dat = nums1[i++];
            } else {
                dat = nums2[j++];
            }
            nums.push_back(dat);
        }
        while(i<m)
            nums.push_back(nums1[i++]);
        while(j<n)
            nums.push_back(nums2[j++]);
        
        if(x%2!=0)
            return nums[x/2];
        
        return (nums[x/2]+nums[x/2-1])/2.0;
    }
};
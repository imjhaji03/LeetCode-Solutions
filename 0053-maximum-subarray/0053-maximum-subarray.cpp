class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int currsubsum = nums[0];
        int maxsubsum = nums[0];

        for(int i = 1; i < n; i++){
            currsubsum = max(nums[i], currsubsum+nums[i]);
            maxsubsum = max(maxsubsum, currsubsum);
        };
        return maxsubsum; 

    }
};
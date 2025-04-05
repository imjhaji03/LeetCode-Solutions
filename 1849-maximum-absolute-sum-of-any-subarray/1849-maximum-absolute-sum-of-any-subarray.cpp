class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int currsubsum = nums[0];
        int maxsubsum = nums[0];

        for(int i = 1; i < n; i ++){
            currsubsum = max(nums[i], nums[i]+currsubsum);
            maxsubsum = max(maxsubsum, currsubsum);
            
        }
        currsubsum = nums[0];
        int minsubsum = nums[0];

        for(int i = 1; i < n; i ++){
            currsubsum = min(nums[i], nums[i]+currsubsum);
            minsubsum = min(minsubsum, currsubsum);
         
        }
        
        return max(abs(maxsubsum),abs(minsubsum));
    }
};
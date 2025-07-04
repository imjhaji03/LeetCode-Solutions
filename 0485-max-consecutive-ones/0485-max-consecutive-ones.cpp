class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxcount = 0;
        int count = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                count++;
                maxcount = max(count, maxcount);
            }
            else if(nums[i] != 1) {
                count = 0;
            }
        }
        return maxcount;
        
    }
};
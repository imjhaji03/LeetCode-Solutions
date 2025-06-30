class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int res = -1;
        if(nums.size() > 2){
            res = nums[1];
        }
        
        return res;
        
    }
};
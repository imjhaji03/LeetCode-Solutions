class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int local = 0;

        for(int i = 0; i < n; i++){
            local += nums[i];
            if(local > 0){
                res = max(res, local);
            }
            if(local < 0){
                local = 0;
            }
        }
        return res;
        
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MIN;
        int local = 0;

        for(int i = 0; i < n; i++){
            local += nums[i];
            if(local > res){
                res = local;
            }
            if(local < 0){
                local = 0;
            }
        }
        return res;
        
    }
};
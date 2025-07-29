class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        vector<int> res;

        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                res.push_back(nums[i]);
            }
        }

        for(int i = 0; i < res.size(); i++){
            nums[i] = res[i];
        }
        for(int i = res.size(); i < n; i++){
            nums[i] = 0;
        }
    }
};
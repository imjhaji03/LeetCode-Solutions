class Solution {
public:
    int arraySign(vector<int>& nums) {
        int zero = 0;
        int positive = 0;
        int negative = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                zero++;
            }
            if(nums[i] > 0){
                positive++;
            }
            if(nums[i] < 0){
                negative++;
            }
        }
        if(zero > 0){
            return 0;
        }
        else if(negative % 2 != 0){
            return -1;
        }
        else {
            return 1;
        }
        
    }
};
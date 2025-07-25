class Solution {
public:
    int maxSum(vector<int>& nums) {
        bool flag = false;
        int total = 0;
        set<int> unique;
        int high = INT_MIN;

        for(int val : nums){
            if(val >= 0){
                flag =  true;
                if(val > 0){
                    unique.insert(val);
                }
            }
            else{
                high = max(high, val);
            }
        }
        if(flag){
            for(int val : unique){
                total += val;
            }
            return total;
        }
        return high;
    }
};
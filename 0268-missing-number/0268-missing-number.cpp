class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        int tsum = (n*(n+1))/2;

        int i = 0;

        while(i < n){
            sum += nums[i];

            i++;
        }

        return tsum-sum;

        
    }
};
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long lsum = 0;
        long long rsum = 0;
        long long totalsum = 0;
        int splitcount = 0;
        for(int i = 0 ; i < n; i++){
            totalsum = totalsum+nums[i];
        }
        for(int i = 0; i < n-1; i++){
            lsum = lsum + nums[i];
            rsum = totalsum - lsum;

            if(lsum >= rsum){
                splitcount++;
            }
        }
        return splitcount;
    }
};
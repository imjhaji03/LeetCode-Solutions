class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> ans(nums.size());
        int pindex = 0;
        int nindex = 1;
        for(int i =0; i<nums.size(); i++){
            if(nums[i]>0){
                ans[pindex] = nums[i];
                pindex+=2;
            }
            else{
                ans[nindex] = nums[i];
                nindex+=2;
            }
        }
        return ans;
        
    }
};
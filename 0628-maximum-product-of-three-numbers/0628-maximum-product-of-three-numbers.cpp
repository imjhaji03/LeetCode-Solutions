class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        

        long long res1 = nums[n-1]*nums[n-2]*nums[n-3];
        long long res2 = nums[n-1]*nums[0]*nums[1];
        return max(res1, res2);
        
    }
};
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mpp;

        int ans = 0;

        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }
        for(auto it : mpp){
            if(it.second == 2){
                ans ^= it.first;
            }
        }
        return ans;
        
    }
};
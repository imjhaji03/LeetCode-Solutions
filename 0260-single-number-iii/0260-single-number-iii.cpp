class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mpp;
        vector<int> result;

        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }
        for(auto it : mpp){
            if(it.second == 1){
                result.push_back(it.first);
            }
        }
        return result;
    }
};
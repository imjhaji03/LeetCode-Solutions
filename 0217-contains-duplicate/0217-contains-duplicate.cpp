class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>res;
        for(int i = 0; i < nums.size(); i++){
            res[nums[i]]++;
        }
        for(auto it : res){
            if(it.second > 1){
                return true;
            }
        }
        return false;
        
    }
};
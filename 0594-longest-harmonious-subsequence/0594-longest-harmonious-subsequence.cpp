class Solution {
public:
    int findLHS(vector<int>& nums) {
        int result = 0;
        unordered_map<int,int> mpp;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }

        for(auto it : nums){
            int minnum = it;
            int maxnum = it+1;
            if(mpp.count(maxnum)){
                result = max(result, mpp[minnum]+mpp[maxnum]);
            }
        }

        return result;
        
    }
};
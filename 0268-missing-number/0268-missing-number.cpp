class Solution {
public:

    int sortingmethod(vector<int> & nums){
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i == nums[i]) continue;
            else {
                return i;
            }
        }
        return nums.size(); // corner case -> What if last element is missing.
    }
    int missingNumber(vector<int>& nums) {
        return sortingmethod(nums);
        
    }
};
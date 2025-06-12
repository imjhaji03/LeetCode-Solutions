class Solution {
public:
    int removeDuplicates(vector<int>& nums) { //Two pointer
        int n = nums.size();

        int i = 0; 
        for(int j = 1; j < n; j++){
            if(nums[i] != nums[j]){
                i++; // pehele yaha per isko update kero
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};
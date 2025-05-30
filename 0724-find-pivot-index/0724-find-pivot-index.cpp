class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int totalsum = 0;

        for(int i = 0; i < n; i ++){
            totalsum += nums[i];
        }

        int cs = 0;
        for(int i = 0; i < n; i ++){
            
            int ls = cs;

            int rs = totalsum - cs - nums[i];

            if(rs == ls){
                return i;
            }

            cs += nums[i];
        }

        return -1;

        
    }
};
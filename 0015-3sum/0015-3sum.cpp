class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result; 
        int n = nums.size();
        if(n < 3) {
            return {}; 
        }
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 2; i++) {
       
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int n1 = nums[i];
            int target = -n1; 

            int left = i + 1;
            int right = n - 1;

            while(left < right) {
                int sum = nums[left] + nums[right];
                if(sum < target) {
                    left++;
                } else if(sum > target) {
                    right--;
                } else {
                    result.push_back({n1, nums[left], nums[right]});

                    
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    while(left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
            }
        }

        return result;
    }
};
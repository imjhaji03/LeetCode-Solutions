class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // 1st Approach XOR
        // int n = nums.size();
        // int ans = 0;
        // for(int i = 0; i < n; i++){
        //     ans = ans^nums[i];
        // }
        // return ans;
        int n = nums.size(); 

        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                return nums[mid];
            }

            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1])
                || (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                
                low = mid + 1;
            }

            else {

                high = mid - 1;
            }
        }

        return -1;

        
    }
};
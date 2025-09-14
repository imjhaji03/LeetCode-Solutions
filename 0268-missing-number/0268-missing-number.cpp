class Solution {
public:

    int xormethod(vector<int> &nums){
        int ans = 0;

        // Xor of all the elements
        for(int i = 0; i < nums.size(); i++){
            ans ^= nums[i];
        }

        // Xor of the range [0, N];
        for(int i = 0; i <= nums.size(); i++){
            ans ^= i;
        }

        return ans;
    }

    int sortingmethod(vector<int> &nums){
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
        return xormethod(nums);
        
    }
};
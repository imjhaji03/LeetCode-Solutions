class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
         vector<int> ans(nums.size());
    int left = 0, right = nums.size() - 1;
    int position = nums.size() - 1;

    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare > rightSquare) {
            ans[position] = leftSquare;
            left++;
        } else {
            ans[position] = rightSquare;
            right--;
        }
        position--;
    }
    return ans;
        
    }
};
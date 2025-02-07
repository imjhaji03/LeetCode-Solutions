class Solution {
public:
    int leftmost(vector<int> &nums, int target, int n){
        int start = 0;
        int end = n-1;
        int leftmost = -1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid] == target){
                leftmost = mid;
                end = mid-1;
            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return leftmost;
    };


    int rightmost(vector<int> &nums, int target, int n){
        int start = 0;
        int end = n-1;
        int rightmost = -1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid] == target){
                rightmost = mid;
                start = mid+1;
            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return rightmost;
    };
    vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
     
        
    int left_most = leftmost(nums, target, n);
    int right_most = rightmost(nums, target, n);

    return{left_most,right_most};

    }
};
class Solution {
public:
    int findPivot(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (mid < end && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            if (mid > start && nums[mid] < nums[mid - 1]) {
                return mid - 1;
            }

            if (nums[start] <= nums[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return -1;
    }

    int binarySearch(vector<int>& nums, int start, int end, int target) {
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;

        int pivotIndex = findPivot(nums);

        if (pivotIndex == -1) {
            return binarySearch(nums, 0, n - 1, target);
        }

        if (target >= nums[0] && target <= nums[pivotIndex]) {
            return binarySearch(nums, 0, pivotIndex, target);
        } else {
            return binarySearch(nums, pivotIndex + 1, n - 1, target);
        }
    }
};

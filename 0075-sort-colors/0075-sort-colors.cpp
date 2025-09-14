class Solution {
public:
    void sortColors(vector<int>& nums) {
        // using stl TC O(nlongn) SC O(n)
        // sort(nums.begin(), nums.end());

        // using countmethod TC O(n) SC O(1)
        // here we are overwriting it so this is not a inplace sorting
        // int zerocount = 0;
        // int onecount = 0;
        // int twocount = 0;

        // for(int i = 0; i < nums.size(); i++){
        //     if(nums[i] == 0){
        //         zerocount++;
        //     }
        //     else if(nums[i] == 1){
        //         onecount++;
        //     }
        //     else{
        //         twocount++;
        //     }
        // }

        // int index = 0;
        // while(zerocount--){
        //     nums[index] = 0;
        //     index++;
        // }
        // while(onecount--){
        //     nums[index] = 1;
        //     index++;
        // }
        // while(twocount--){
        //     nums[index] = 2;
        //     index++;
        // }

        // Inplace Sorting

        // In-place Sorting (Dutch National Flag Algorithm) TC O(n) SC O(1)
        // 1. Initialize three pointers: 'l' for 0s (left), 'm' for current element (middle), 'h' for 2s (right).
        // 2. Iterate while 'm' is less than or equal to 'h'.
        // 3. If nums[m] is 0, swap nums[l] and nums[m], then increment 'l' and 'm'.
        // 4. If nums[m] is 1, just increment 'm'.
        // 5. If nums[m] is 2, swap nums[m] and nums[h], then decrement 'h'.
        //    (Note: 'm' is not incremented here because the swapped element at 'h' could be 0, 1, or 2 and needs   to be checked.)

        int l = 0;
        int m = 0;
        int h = nums.size()-1;

        while(m <= h){
            if(nums[m] == 0){
                swap(nums[l],nums[m]);
                l++;
                m++;
            }
            else if(nums[m] == 1){
                m++;
            }
            else{
                swap(nums[m],nums[h]);
                h--;
            }
        } 
        
    }
};
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
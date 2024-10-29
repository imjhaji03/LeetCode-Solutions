class Solution {
public:
    void sortColors(vector<int>& nums) {
        int countzero = 0;
        int countone = 0;
        int counttwo = 0;
        for ( int i = 0; i< nums.size(); i++) {
            if ( nums[i] == 0) {
                countzero++;
            }
            else if ( nums[i] == 1) {
                countone++;
            }
            else if  ( nums[i] == 2) {
                counttwo++;
            }

        }

        int index = 0;
        while (countzero-- ) {
            nums[index] = 0;

            index++ ;
        }
        while (countone-- ) {
            nums[index] = 1;

            index++ ;
        }
        while (counttwo-- ) {
            nums[index] = 2;

            index++ ;
        }

    }
};
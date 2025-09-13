class Solution {
public:
    int bruteforce(vector<int>& nums){
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int lsum = 0;
            int rsum = 0;
            for(int j = 0; j < i; j++){
                lsum += nums[j];
            }
            for(int j = i+1; j < n; j++){
                rsum += nums[j];
            }

            if(lsum == rsum ) return i;
        }
        return -1;
    }

    int optimizedapproach(vector<int> & nums){
        vector<int> lsum(nums.size(), 0);
        vector<int> rsum(nums.size(), 0);
        // calc the lsum
        for(int i = 1; i < nums.size(); i++){
            lsum[i] = lsum[i-1] + nums[i-1];
        }
        // calc the rsum
        for(int i = nums.size()-2; i >= 0; i--){
            rsum[i] = rsum[i+1] + nums[i+1];
        }

        for(int i = 0; i < nums.size(); i++){ // using the interation from 1 -> n as it need leftmost pivot index
            if(lsum[i] == rsum[i]){
                return i;
            }
        }
        return -1;

    }
    int pivotIndex(vector<int>& nums) {

        return optimizedapproach(nums);
        
    }
};
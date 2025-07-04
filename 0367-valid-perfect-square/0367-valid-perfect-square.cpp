class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 0;
        int high = num;
      
        while(low <= high){
            long long mid = low + (high - low)/2;
            long long val = mid * mid;
            if(val == (long long)num){
                return true;
            }
            else if(val < (long long)num){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return false;
        
    }
};
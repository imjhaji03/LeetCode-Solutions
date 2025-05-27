class Solution {
public:
    bool isPowerOfTwo(int n) {

        bool flag = false;
        if(n <= 0){
            return false;
        }
        else if((n & n-1) == 0){
            return true;
        }

        return flag;
        
    }
};
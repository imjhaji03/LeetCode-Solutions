class Solution {
public:

    int rev(int x){
        int rev = 0;
        while(x){
            rev = rev*10 + x%10;
            x /= 10;
        }
        return rev;
    }
    bool isSameAfterReversals(int num) {

        return (rev(rev(num)) == num);

    }
};
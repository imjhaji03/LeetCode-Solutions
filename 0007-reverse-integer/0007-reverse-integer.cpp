class Solution {
public:
    int reverse(int x) {
        long rev = 0;
        int temp = x;
        while(temp){
            rev = rev*10 + temp%10;
            temp /= 10;
        }

        if(rev > INT_MAX || rev < INT_MIN){
            return 0;
        }

        return (int)rev;
        
    }
};
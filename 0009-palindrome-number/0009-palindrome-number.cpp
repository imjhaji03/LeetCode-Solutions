class Solution {
public:
    bool isPalindrome(int x) {
        long long rev = 0;
        long long temp = x;

        while(temp > 0){
            long long num = temp % 10;
            rev = rev * 10 + num;
            temp = temp / 10;
        }
        if(x == rev){
            return true;
        }
        else{
            return false;
        }
        
    }
};
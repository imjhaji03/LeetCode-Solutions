class Solution {
public:
    int gcd(int n1, int n2){
        while(n1 > 0 && n2 > 0) {
            
            if(n1 > n2) {
                n1 = n1 % n2;
            }
            
            else {
                n2 = n2 % n1;
            }
        }
    
        if(n1 == 0) return n2;
    
        return n1;
    }    
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int result = gcd(nums[0], nums[n-1]);
        return result; 
    }
};
class Solution {
public:
    int minimumDeletions(string s) {
        int dp = 0;     
        int b_count = 0;  
        
        for (char c : s) {
            if (c == 'b') {
                b_count++;
            } else { 
                dp = min(dp + 1, b_count);
            }
        }
        
        return dp;
    }
};
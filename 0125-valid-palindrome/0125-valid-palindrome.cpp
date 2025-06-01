class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> ch;
        for(char c : s){
            if (isalnum(c)){
                ch.push_back(tolower(c));
            }    
            
        }

        int m = 0;
        int n = ch.size()-1;


        bool flag = false;

        while(m<n){
            
            if(ch[m] != ch[n]){
                return false;
            }

            m++;
            n--;
        
        }

        return true;   
    }
};
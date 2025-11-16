class Solution {
public:
    string largestOddNumber(string num) {
        int j = -1;
        int n = num.size()-1;

        for(int i = n; i >= 0; i--){
            if((num[i] - '0') % 2 == 1){
                j = i;
                break;
            }
        }
        if(j == -1) return "";
        
        int i = 0;
        while(i <= j && num[i] == '0') i++;

        return num.substr(i, j - i + 1);
    }
};
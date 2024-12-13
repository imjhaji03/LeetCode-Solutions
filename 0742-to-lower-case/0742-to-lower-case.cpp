class Solution {
public:
    string toLowerCase(string s) {
        int index = 0;
        while(s[index] !='\0'){
            char currentchar = s[index];

            if(currentchar >= 'A' && currentchar <= 'Z'){
                s[index] = currentchar -'A'+'a';
            }

            index++;
        }
        
        return s;
    }
};
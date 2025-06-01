class Solution {
public:
    string reverseWords(string s) {
        
        // Approach using stringstream:

        // Use stringstream to split the input string s into individual words.

        // Store each word in reverse order by prepending it to a result string.

        // After the loop, the result string will have an extra space at the end.

        // Use substr(0, n - 1) to remove the trailing space and return the final result.

        // stringstream ss(s);

        // string token = " ";
        // string result = "";

        // while(ss>>token){
        //     result = token + " " + result;
        // }

        // int n = result.size();

        // return result.substr(0,n-1);


        reverse(s.begin(),s.end());

        int n = s.size();

        int i = 0;
        
        int l = 0, r = 0;

        while(i < n){
            while(i < n && s[i] != ' '){
                s[r] = s[i];
                i++;
                r++;
            }
            if(l<r){
                reverse(s.begin()+l, s.begin()+r);
                s[r] = ' ';
                r++;

                l = r;
            }

            i++;
        }

        return s.substr(0, r-1);

    }
};
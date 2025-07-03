class Solution {
public:
    char kthCharacter(int k) {
        int index = k-1;
        string result = "a";

        while(result.size() < k) {
            int n = result.size();
            for(int i = 0; i < n; i++) {
                char ch = result[i] == 'z' ? 'a' : result[i]+1;
                result.push_back(ch);
            }
        }

        return result[index];
        
    }
};
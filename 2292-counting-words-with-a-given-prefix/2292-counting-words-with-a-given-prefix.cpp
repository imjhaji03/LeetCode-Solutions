class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int totalcount = 0;
        for (string& word : words) {
            if (word.find(pref) == 0) {
                totalcount++;
            }
        }
        return totalcount;
    }
};
class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int, int> mpp;
        string s = to_string(n);
        for(int i = 0; i < s.length(); i++){
            mpp[s[i]]++;
        }
        int score = 0;

        for(auto it : mpp){
            score += (it.first - '0') * (it.second);
        }
        return score;
        
    }
};
class Solution {
public:
    bool isAnagram(string s, string t) {
        bool flag = true;

        if(s.length() != t.length()){
            flag = false;
        }
        unordered_map<char,int> mpp;
        for(int i = 0; i < s.length(); i++){
            mpp[s[i]]++;
        }
        for(int i = 0; i < t.length(); i++){
            if(mpp[t[i]] != 0){
                mpp[t[i]]--;
            }
        
        }
        for(auto it : mpp){
            if(it.second != 0)
            flag = false;
        }
        return flag;
    }
};
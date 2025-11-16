class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int smap[256] = {0}, tmap[256] = {0};

        for(int i = 0; i < s.length(); i++){
            if(smap[s[i]] != tmap[t[i]]) return false;

            smap[s[i]] = i + 1;
            tmap[t[i]] = i + 1;

        }
        return true;

    }
};
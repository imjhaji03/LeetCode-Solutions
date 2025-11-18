class Solution {
public:
typedef pair<char,int> P;
    string frequencySort(string s) {
        vector<P> vcc(123);

        for(auto ch : s){
            int freq = vcc[ch].second;
            vcc[ch] = {ch, freq+1};
        }

        auto lambda =[&](P &p1, P &p2){
            return p1.second > p2.second;
        };
        sort(vcc.begin(),vcc.end(), lambda);

        string result = "";

        for(int i = 0; i <= 122; i++){
            if(vcc[i].second > 0){
                char ch = vcc[i].first;
                int freq = vcc[i].second;
                string temp = string(freq,ch);
                result += temp;
            }
        }
        return result;
    }
};
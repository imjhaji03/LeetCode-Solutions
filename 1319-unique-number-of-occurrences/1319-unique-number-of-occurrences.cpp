class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mpp;

        for(int i = 0; i < arr.size(); i++){
            mpp[arr[i]]++;
        }
        unordered_set<int> stt;

        for(auto it : mpp) {
            int freq = it.second; 
            
            if(stt.find(freq) != stt.end())
                return false;
            stt.insert(freq);
        }
        
        return true;
        
    }
};
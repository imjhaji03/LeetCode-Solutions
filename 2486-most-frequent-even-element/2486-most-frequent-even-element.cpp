class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
   
        unordered_map<int,int> mpp;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 0){
                mpp[nums[i]]++;
            }
        }
        if(mpp.empty()){
            return -1;
        }
        int maxfreq = 0;
        int minnum;

        for(auto it : mpp){
            int freq = it.second;
            int num = it.first;
            if(freq > maxfreq){
                maxfreq = freq;
                minnum = num;
            }
            else if(freq == maxfreq){
                minnum = min(minnum, num);
            }
        }
        
        return minnum;
        
    }
};
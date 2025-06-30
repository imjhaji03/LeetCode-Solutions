class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int maxcount = 0;
        int count = 0;

        for(int i = 0; i < arr.size(); i++){
            if(arr[i] % 2 != 0){
                count++;
                maxcount = max(maxcount, count);
            }
            else{
                count = 0;
            }
        }
        if(maxcount >= 3){
            return true;
        }
        else{
            return false;
        }
        
    }
};
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int n = cost.size();
        int res = 0;

        for(int i = 0; i < n; i++){
            if((i+1) % 3 == 0){
                continue;
            }
            else{
                res += cost[i];
            }

        }
        return res;
        
    }
};
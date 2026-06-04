class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        int cnt1 = 0;
        int ele1;
        int cnt2 = 0;
        int ele2;

        for(auto it : nums){
            if(it == ele1){
                cnt1++;
            }
            else if(it == ele2){
                cnt2++;
            }
            else if(cnt1 == 0){
                ele1 = it;
                cnt1 = 1;
            }
            else if(cnt2 == 0){
                ele2 = it;
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == ele1){
                count1++;
            }
            else if(nums[i] == ele2){
                count2++;
            }
        }
        if(count1 > n/3){
            res.push_back(ele1);
        }
        if(count2 > n/3){
            res.push_back(ele2);
        }

        return res;

    }
};
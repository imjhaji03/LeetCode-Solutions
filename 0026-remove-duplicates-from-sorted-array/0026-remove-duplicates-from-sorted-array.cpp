class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;

        for(int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        }
        nums.clear();
        int index = 0;
        for(auto it : st){
            nums.push_back(it);
            index ++;
        }
        return nums.size();
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0;
        int j = n-1;
// Two ppointer Algorithm
        while(i<j){
            if(numbers[i]+numbers[j] > target){
                j--;
            }
            else if(numbers[i]+numbers[j] < target){
                i++;
            }
            else{
                return{i+1,j+1};           // 1 based indexing ke liye i+1; j+1
            }
        }
        return{};
    }

};
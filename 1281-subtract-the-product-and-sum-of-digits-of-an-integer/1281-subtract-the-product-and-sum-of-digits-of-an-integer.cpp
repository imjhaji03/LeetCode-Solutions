class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0;
        int product = 1;

        int temp = n;

        while(temp > 0){
            int s = temp % 10;
            sum += s;
            product *= s;
            temp /= 10;
        }

        return (product-sum);
        
    }
};
class Solution {
public:
    int climbStairs(int n) {
        int num1 = 1, num2 = 1, temp;
        for ( int i = 2; i <= n ; i++ ) {
            temp = num1 + num2;
            num1 = num2;
            num2 = temp;
        }

        return num2;
    }
};


class Solution {
public:
    int climbStairs(int n) {
        if ( n <= 2 ){
            return n;
        }

        int step = 1, step2 = 2;
        for ( int i = 2; i < n; i++ ) {
            int nextStep = step + step2;
            step = step2;
            step2 = nextStep;
        }

        return step2;
    }
};

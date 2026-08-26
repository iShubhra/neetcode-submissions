class Solution {
public:
    int climbStairs(int n) {
        if ( n <= 1 ) return n;
        int first = 1, second = 2, next;
        for ( int i = 2; i < n; i++ ){
            next = first + second;
            first = second;
            second = next;
        }

        return second;
    }
};

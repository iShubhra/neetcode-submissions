class Solution {
public:
    int arrangeCoins(int n) {
        long long left = 1 , right = n, mid, sum;
        while ( left <= right ){
            mid = left + ( right - left ) / 2;
            sum = mid * ( 1 + mid ) / 2;
            if ( sum == n ) {
                return mid;
            }else if ( sum > n ) {
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }

        return left - 1;
    }
};

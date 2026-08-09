class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for ( int i = 0; i <= n; i++ ){
            res[i] = countOneBit(i);
        }

        return res;
    }

    int countOneBit(int n ){
        int result = 0;
        for ( int i = 0; i < 32; i++ ){
            if ( n & 1) result++;
            n = n >> 1;
        }

        return result;
    }
};

class Solution {
public:
    unordered_map<int,int> m;
    int climbStairs(int n) {
        if (n == 0 ) return 1;
        if ( n < 0 ) return 0;

        int num1 = ( n - 1 );
        int num2 = ( n - 2 );
        auto it = m.find(num1);
        int res1, res2;
        if ( it != m.end() ){
            res1 = it->second;
        }else {
            res1 = climbStairs( num1 );
            m[num1] = res1;
        }

        it = m.find(num2);
        if ( it != m.end() ){
            res2 = it->second;
        }else {
            res2 = climbStairs( num2 );
            m[num2] = res2;
        }

        return res1 + res2;
    }
};

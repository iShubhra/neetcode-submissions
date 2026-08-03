class Solution {
public:
    bool isPossible(vector<int>& piles, int h, int k) {
        for ( int i = 0; i < piles.size(); i++ ){
            h -= piles[i] / k;
            if ( piles[i] % k > 0  ){
                h--;
            }
        }

        return h >= 0;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int result = *max_element(piles.begin(), piles.end());

        int left, right;
        left = 1;
        right = result;

        while ( left <= right ) {
            int mid = left + ( right - left) / 2;
            if ( isPossible(piles, h, mid) ){
                result = min(result, mid);
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return result;
    }
};
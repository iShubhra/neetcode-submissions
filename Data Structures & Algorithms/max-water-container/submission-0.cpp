class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size() - 1, result = 0, minVal;
        while ( i < j ) {
            minVal = min(heights[i], heights[j]);
            result = max(result, (minVal * ( j - i)) );
            if ( heights[i] > heights[j] ){
                j--;
            }else {
                i++;
            }
        }

        return result;
    }
};

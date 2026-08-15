class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), total = m * n;
        vector<int>arr(n * m);
        int left = 0, right = m - 1, top = 0, bottom = n - 1, idx = 0;
        while ( idx < total) {
            // left to right
            for ( int i = left; i <= right && idx < total; i++ ){
                arr[idx] = matrix[top][i];
                idx++;
            }
            top++;

            // top to bottom
            for ( int i = top; i <= bottom && idx < total; i++ ){
                arr[idx] = matrix[i][right];
                idx++;
            }
            right--;
            
            // right to left
            for ( int i = right; i >= left && idx < total; i-- ) {
                arr[idx] = matrix[bottom][i];
                idx++;
            }
            bottom--;

            // bottom to top
            for ( int i = bottom; i >= top && idx < total; i-- ){
                arr[idx] = matrix[i][left];
                idx++;
            }
            left++;
        }

        return arr;
    }
};

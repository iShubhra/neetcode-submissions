class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for ( int col = 0; col < n; col++){
            for ( int row = 0; row < n / 2; row++ ){
                swap(matrix[row][col], matrix[n - 1 - row][col]);
            }
        }

        for ( int row = 0; row < n; row++ ){
            for ( int col = row; col < n; col++ ){
                swap(matrix[row][col], matrix[col][row]);
            }
        }
    }
};

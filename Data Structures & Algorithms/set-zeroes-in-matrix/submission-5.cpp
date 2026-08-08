class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        // set first row & first col as 0
        bool isFirstColZero = false, isFirstRowZero = false;
        for ( int i = 0; i < matrix.size(); i++ ){
            for ( int j = 0; j < matrix[0].size(); j++ ) {
                if ( i == 0 && matrix[i][j] == 0 ){
                    isFirstColZero = true;
                }

                if ( j == 0 && matrix[i][j] == 0 ){
                    isFirstRowZero = true;
                }

                if ( matrix[i][j] == 0 ) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // start row & col from 1 
        for ( int i = 1; i < matrix.size(); i++ ){
            for ( int j = 1; j < matrix[0].size(); j++ ) {
                if ( matrix[i][0] == 0 || matrix[0][j] == 0 ){
                    matrix[i][j] = 0;
                }
            }
        }

        // we have mark first row & col mark as zero if its req
        if ( isFirstColZero ){
            for ( int i = 0; i < matrix[0].size(); i++ ) {
                matrix[0][i] = 0;
            }
        }

        if ( isFirstRowZero ){
            for ( int i = 0; i < matrix.size(); i++ ) {
                matrix[i][0] = 0;
            }
        }
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for ( int row = 0; row < grid.size(); row++ ){
            for ( int col = 0; col < grid[0].size(); col++ ){
                if ( grid[row][col] == '1' ){
                    islands(grid, row, col);
                    result++;
                }
            }
        }

        return result;
    }

    void islands(vector<vector<char>>& grid, int row, int col){
        if ( row >= grid.size() || col >= grid[0].size() 
        || row < 0 || col < 0 || grid[row][col] == '0') {
            return;
        }

        grid[row][col] = '0';

        islands(grid, row + 1, col);
        islands(grid, row - 1, col);
        islands(grid, row , col + 1);
        islands(grid, row , col - 1);
        return;
    }
};

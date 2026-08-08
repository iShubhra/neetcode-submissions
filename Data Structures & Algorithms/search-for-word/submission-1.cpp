class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for ( int r = 0; r < board.size(); r++ ){
            for ( int c = 0; c < board[0].size(); c++ ){
                if ( board[r][c] == word[0] && dfs(board, word, 0, r, c) ) {
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int idx, int row, int col) {
        if ( idx == word.size() ) {
            return true;
        }

        if ( row >= board.size() || col >= board[0].size() || word[idx] != board[row][col] || board[row][col] == '0'){
            return false;
        }


        char ch = board[row][col];
        board[row][col] = '0';
        bool res = false;
        res = dfs(board, word, idx + 1, row + 1, col) ||
        dfs(board, word, idx + 1, row - 1, col) ||
        dfs(board, word, idx + 1, row, col + 1) ||
        dfs(board, word, idx + 1, row, col - 1);
        
        board[row][col] = ch;
        return res;
    }
};

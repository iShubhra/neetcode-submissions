func isValidSudoku(board [][]byte) bool {
	return isValid(board, 0, 0)
}

func isValid(board [][]byte, row, col int) bool {
	if row == len(board) {
		return true
	}

	nextRow := row
	nextCol := col + 1

	if nextCol == len(board[0]) {
		nextRow++
		nextCol = 0
	}

	if board[row][col] != '.' && isExists(board, board[row][col], row, col) {
        return false
    }

    return isValid(board, nextRow, nextCol)
}


func isExists(board [][]byte, num byte, row, col int) bool{
	for i := 0; i < len(board); i++ {
		if board[i][col] == num  && i != row {
			return true
		}
	}

	for i := 0; i < len(board[0]); i++ {
		if board[row][i] == num  && col != i {
			return true
		}
	}

	startRow := ( row / 3 ) * 3
	startCol := ( col / 3 ) * 3

	for i := startRow; i < startRow + 3 ; i++ {
		for j := startCol; j < startCol + 3; j++ {
			if board[i][j] == num  && i != row && j != col {
				return true
			}
		}
	}

	return false
}
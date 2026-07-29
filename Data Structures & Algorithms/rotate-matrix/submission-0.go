func rotate(matrix [][]int)  {
    colStart,  colEnd := 0, len(matrix[0]) - 1
    rowStart, rowEnd := 0, len(matrix) / 2
    for i := rowStart; i < rowEnd; i++ {
        for j := colStart; j < colEnd; j++ {
            rotateMatrix(matrix,i, j)
        }
        colStart++
        colEnd--
    }

}

func rotateMatrix(matrix [][]int, row, col int){
    size := len(matrix) - 1
    nextRow := col
    nextCol := size - row
    value := matrix[row][col]
    for i := 0; i < 4; i++ {
        nextValue := matrix[nextRow][nextCol]
        matrix[nextRow][nextCol] = value
        row = nextRow
        col = nextCol
        nextRow = col
        nextCol = size - row
        value = nextValue
    }
}
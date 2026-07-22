func spiralOrder(matrix [][]int) []int {
    left := 0
	right := len(matrix[0]) - 1
	top := 0
	bottom := len(matrix) - 1
	total := len(matrix) * len(matrix[0])
	arr := make([]int, total)
	pos := 0
	for pos < total {
		// left to right ( top )
		for i := left; i <= right && pos < total; i++ {
			arr[pos] = matrix[top][i]
			pos++
		}
		top++

		// top to bottom ( right )
		for i := top; i <= bottom && pos < total; i++ {
			arr[pos] = matrix[i][right]
			pos++
		}
		right--

		// right to left ( bottom )
		for i := right; i >= left && pos < total; i-- {
			arr[pos] = matrix[bottom][i]
			pos++
		}
		bottom--

		// bottom to top ( left )
		for i := bottom; i >= top && pos < total; i-- {
			arr[pos] = matrix[i][left]
			pos++
		}
		left++
	}

	return arr
}

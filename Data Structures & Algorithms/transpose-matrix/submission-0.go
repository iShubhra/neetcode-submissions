func transpose(matrix [][]int) [][]int {
	result := make([][]int, len(matrix[0]))
	for i := 0; i < len(matrix[0]); i++ {
		arr := make([]int, len(matrix))
		for j := 0; j < len(matrix); j++ {
			arr[j] = matrix[j][i]
		}
		result[i] = arr
	}

	return result
}

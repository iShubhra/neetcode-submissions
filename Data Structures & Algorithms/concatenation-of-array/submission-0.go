func getConcatenation(nums []int) []int {
	n := len(nums)
    result := make([]int, 2 * n)
	for i, num := range nums {
		result[i], result[i + n] = num, num
	}

	return result
}

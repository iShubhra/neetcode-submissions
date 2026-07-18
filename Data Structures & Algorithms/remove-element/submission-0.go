func removeElement(nums []int, val int) int {
    count := 0
	for _, num := range nums { if num == val { count++ }}
	n := len(nums)
	for i := 0; i < n; i++ {
		for i < n && nums[i] != val {
			i++
		}

		j := i + 1
		for j < n && nums[j] == val {
			j++
		}

		if i < n && j < n {
			nums[i], nums[j] = nums[j], nums[i]
		}
	}

	return n - count
}

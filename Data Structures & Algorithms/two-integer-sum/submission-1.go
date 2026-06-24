func twoSum(nums []int, target int) []int {
    hashMap := make(map[int]int)
	for idx, num := range nums {
		if index, ok := hashMap[target - num]; ok {
			return []int{index, idx}
		}
		hashMap[num] = idx
	}

	return nil
}

func containsNearbyDuplicate(nums []int, k int) bool {
	hashMap := make(map[int]int)
	for idx, num := range nums {
		if index, ok := hashMap[num]; ok && idx - index <= k {
			return true
		}
		hashMap[num] = idx
	}

	return false
}

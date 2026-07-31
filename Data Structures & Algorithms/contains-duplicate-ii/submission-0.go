func containsNearbyDuplicate(nums []int, k int) bool {
	hashMap := make(map[int]struct{})
	for i := 0; i < k; i++ {
		if _, ok := hashMap[nums[i]]; ok {
			return true
		}
		hashMap[nums[i]] = struct{}{}
	}

	for i := k; i < len(nums); i++ {
		if _, ok := hashMap[nums[i]]; ok {
			return true
		}
		hashMap[nums[i]] = struct{}{}
		delete(hashMap, nums[i - k])
	}

	return false
}

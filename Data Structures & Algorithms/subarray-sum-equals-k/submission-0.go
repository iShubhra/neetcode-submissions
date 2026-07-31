func subarraySum(nums []int, k int) int {
	prefixArr := make([]int, len(nums))
	prefixArr[0] = nums[0]

	hashMap := make(map[int]int, len(nums))
	hashMap[0] = 1

	result := 0

	for i := 1; i < len(nums); i++ {
		prefixArr[i] = nums[i] + prefixArr[i - 1]
	}

	for _, prefixSum := range prefixArr {
		if sumVal, ok := hashMap[prefixSum - k]; ok {
			result += sumVal
		}
		hashMap[prefixSum]++
	}

	return result
}

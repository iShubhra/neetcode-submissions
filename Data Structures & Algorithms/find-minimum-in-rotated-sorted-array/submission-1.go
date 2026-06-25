func findMin(nums []int) int {
	left := 0
	right := len(nums) - 1
	result := nums[0]

	for left <= right {
		mid := left + ( right - left ) / 2
		result = min(result, nums[mid])
		if nums[left] <= nums[mid] && nums[left] > nums[right] {
			left = mid + 1
		}else {
			right = mid - 1
		}
	}

	return result
}

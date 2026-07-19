func search(nums []int, target int) int {
	return binarySearch(nums, 0, len(nums) - 1, target)
}

func binarySearch(nums []int, left, right, k int) int {
	if left > right {
		return -1
	}

	mid := left + ( right - left ) / 2
	if nums[mid] == k {
		return mid
	}else if nums[mid] > k {
		return binarySearch(nums, left, mid - 1, k)
	}

	return binarySearch(nums, mid + 1, right, k)
}
func rotate(nums []int, k int) {
	k = k % len(nums)
	size := len(nums) - 1
	reverse(nums, 0, size)
	reverse(nums, 0, k - 1)
	reverse(nums, k, size)
}

func reverse(nums []int, left, right int) {
	for left < right {
		nums[left], nums[right] = nums[right], nums[left]
		left++
		right--
	}
}

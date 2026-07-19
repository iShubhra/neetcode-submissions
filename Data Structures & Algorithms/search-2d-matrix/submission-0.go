func searchMatrix(matrix [][]int, target int) bool {
	for i := 0; i < len(matrix); i++ {
		left := matrix[i][0]
		right := matrix[i][len(matrix[i]) - 1]
		if left <= target && right >= target {
			if binarySearch(matrix[i], target) {
				return true
			}
		
		}
	}

	return false
}

func binarySearch(nums []int, k int) bool {
	left, right := 0, len(nums) - 1
	for right >= left {
		mid := left + ( right - left ) / 2
		if nums[mid] == k {
			return true
		}else if nums[mid] > k {
			right = mid - 1
		}else{
			left = mid + 1
		}
	}

	return false
}
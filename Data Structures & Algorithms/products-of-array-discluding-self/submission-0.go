func productExceptSelf(nums []int) []int {
	zero := 0
	multiplyWithOutZero := 1
	for _, num := range nums {
		if num != 0 {
			multiplyWithOutZero *= num
		}else {
			zero++
		}
	}

	result := make([]int, len(nums))
	if zero >= 2 {
		return result
	}

	if zero == 1 {
		for idx, num := range nums {
			if num == 0 {
				result[idx] = multiplyWithOutZero
			}
		}

		return result
	}


	for idx, num := range nums {
		result[idx] = multiplyWithOutZero / num
	}

	return result
}

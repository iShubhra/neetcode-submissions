func plusOne(digits []int) []int {
	bag := 1
	for i := len(digits) - 1; i >= 0; i-- {
		sum := digits[i] + bag 
		digits[i] = ( sum % 10 )
		bag = sum / 10
	}

	if bag == 1 {
		result := make([]int, len(digits) + 1)
		result[0] = 1
		for i := 1; i < len(result); i++ {
			result[i] = digits[i - 1]
		}

		return result
	}

	return digits
}

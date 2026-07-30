func isHappy(n int) bool {
	hashSet := make(map[int]struct{})
    for n > 1 {
		sum := 0
		for n > 0 {
			sum += (n % 10) * (n % 10)
			n /= 10 
		}

		if _, ok := hashSet[sum]; ok {
			return false
		}
		hashSet[sum] = struct{}{}
		n = sum
	}

	return n == 1
}

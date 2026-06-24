func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	array := make([]byte, 26)
	for i := 0; i < len(s); i++ {
		array[s[i] - 97]++
		array[t[i] - 97]--
	}

	for _, val := range array {
		if val > 0 || val < 0 {
			return false
		}
	}

	return true
}

func lengthOfLongestSubstring(s string) int {
	hashSet := make(map[rune]struct{})
	array := make([]rune, 0)
	result := 0
	for _, b := range s {
		if _, ok := hashSet[b]; ok {
			for _, k := range array {
				delete(hashSet, k)
				array = array[1:]

				if b == k {
					break
				}
			}
		}
		
		hashSet[b] = struct{}{}
		array = append(array, b)
		result = max(result, len(hashSet))
	}

	return result
}

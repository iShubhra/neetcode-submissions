func groupAnagrams(strs []string) [][]string {
	hashMap := make(map[[26]byte][]string)
	for _, str := range strs {
		chars := [26]byte{}
		for _, b := range str {
			chars[b - 97]++
		}
		value, ok := hashMap[chars]
		if !ok {
			hashMap[chars] = []string{str}
		}else{
			hashMap[chars] = append(value, str)
		}
	}

	result := make([][]string,0)
	for _, values := range hashMap {
		result = append(result, values)
	}

	return result
}
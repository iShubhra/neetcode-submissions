func mergeAlternately(word1 string, word2 string) string {
	var result strings.Builder
	i, j := 0, 0
	n, m := len(word1), len(word2)
	for i < n || j < m {
		if i < n {
			result.WriteByte(word1[i])
			i++
		}

		if j < m {
			result.WriteByte(word2[j])
			j++
		}
	}

	return result.String()
}

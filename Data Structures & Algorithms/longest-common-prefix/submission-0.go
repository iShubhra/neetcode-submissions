func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}

    var result strings.Builder
	for i := 0; i < len(strs[0]); i++ {
		for j := 1; j < len(strs); j++ {
			if i > len(strs[j]) - 1 || strs[0][i] != strs[j][i]{
				return result.String()
			}
		}

		result.WriteByte(strs[0][i])
	}

	return result.String()
}

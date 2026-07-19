func reverseString(s []byte) {
	left, right := 0, len(s) - 1
	for right > left {
		s[left], s[right] = s[right], s[left]
		left++
		right--
	}
}

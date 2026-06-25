func isPalindrome(s string) bool {
	i, j := 0, len(s) - 1
	for i < j {
		left := unicode.ToLower(rune(s[i]))
		right := unicode.ToLower(rune(s[j]))

		fmt.Println(string(left), string(right))
		if !onlyAllowedNumberAndLetter(left) {
					fmt.Println("left",string(left), string(right))
			i++
			continue
		}

		if !onlyAllowedNumberAndLetter(right) {
					fmt.Println("right",string(left), string(right))
			j--
			continue
		} 

				fmt.Println("final",string(left), string(right))

		if left != right {
			return false
		}
		i++
		j--
	}

	return true
}


func onlyAllowedNumberAndLetter(s rune) bool {
	if unicode.IsNumber(s) {
		return true
	}

	if unicode.IsLetter(s) {
		return true
	}

	return false
}

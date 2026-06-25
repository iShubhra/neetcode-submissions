func isValid(s string) bool {
    stack := make([]rune, 0)
	for _, b := range s {
		if b == '(' || b == '{' || b == '[' {
			stack = append(stack, b)
		}else if b == ')'{
			if len(stack) == 0 {
				return false
			}else if stack[len(stack) - 1] != '('{
				return false
			}else{
				stack = stack[:len(stack) - 1]
			}
		}else if b == '}'{
			if len(stack) == 0 {
				return false
			}else if stack[len(stack) - 1] != '{'{
				return false
			}else{
				stack = stack[:len(stack) - 1]
			}
		}else if b == ']'{
			if len(stack) == 0 {
				return false
			}else if stack[len(stack) - 1] != '['{
				return false
			}else{
				stack = stack[:len(stack) - 1]
			}
		}
	}


	return len(stack) == 0
}

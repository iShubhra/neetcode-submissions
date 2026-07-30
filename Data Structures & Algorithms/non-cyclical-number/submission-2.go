func isHappy(n int) bool {
	slow, fast := n, sumOfSquare(sumOfSquare(n))
	for slow != fast {
		slow = sumOfSquare(slow)
		fast = sumOfSquare(sumOfSquare(fast))
	}

	return slow == 1
}

func sumOfSquare(n int) int {
	num := 0
	for n > 0 {
		num += (n % 10) * (n % 10)
		n /= 10
	}

	return num
}

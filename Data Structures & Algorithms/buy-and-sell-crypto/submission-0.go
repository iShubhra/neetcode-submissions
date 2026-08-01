func maxProfit(prices []int) int {
	price := prices[0]
    result := 0
    for _, val := range prices {
        price = min(price, val)
        result = max(result, val - price)
    }

    return result
}

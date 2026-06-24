func hasDuplicate(nums []int) bool {
    hashSet := make(map[int]bool)
    for _, num := range nums {
        if hashSet[num] {
            return true
        }
        hashSet[num] = true
    }

    return false
}

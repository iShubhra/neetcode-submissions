func longestConsecutive(nums []int) int {
    hashMap := make(map[int]struct{}, len(nums))
    isExists := func(num int) bool {
        _, ok := hashMap[num]
        return ok
    }

    for _, num := range nums {
        hashMap[num] = struct{}{}
    }

    result := 0
    for num, _ := range hashMap {
        if !isExists(num + 1) {
            count := 1
            num--
            for isExists(num) {
                num--
                count++
            }

            result = max(result, count)
        }
    }

    return result
}

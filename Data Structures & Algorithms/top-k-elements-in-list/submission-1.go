func topKFrequent(nums []int, k int) []int {
    hashMap := make(map[int]int)
    for _, num := range nums {
        hashMap[num]++
    }

    result := make([]int, k)

    for i := 0; i < k ;i++ {
        maxVal := -1
        value := -1
        flag := false
        for key, val := range hashMap {
            if !flag {
                maxVal = val
                value = key
                flag = true
                continue
            }

            if val > maxVal {
                maxVal = val
                value = key
            }
        }
        delete(hashMap, value)
        result[i] = value
    }

    return result
}

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * func guess(num int) int;
 */

func guessNumber(n int) int {
    left, right := 1, n
	for right >= left {
		mid := left + ( right - left ) / 2
		result := guess(mid)
		if result == 0 {
			return mid
		}else if result == - 1 {
			right = mid - 1
		}else{
			left = mid + 1
		}
	}

	return -1
}

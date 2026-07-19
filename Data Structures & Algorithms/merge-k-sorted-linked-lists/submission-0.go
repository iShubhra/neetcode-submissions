/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func mergeKLists(lists []*ListNode) *ListNode {
    node := &ListNode{}
	temp := node
	for {
		minValue := math.MaxInt64
		index := -1
		for i, list := range lists {
			if list != nil {
				if minValue > list.Val {
					minValue = list.Val
					index = i
				}
			}
		}

		if index == - 1 {
			break
		}

		temp.Next = &ListNode{Val : lists[index].Val}
		temp = temp.Next
		lists[index] = lists[index].Next
	}


	return node.Next
}

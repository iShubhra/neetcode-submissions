/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
    newNode := new(ListNode)
	curr := newNode
	for list1 != nil || list2 != nil {
		if list1 != nil && list2 != nil {
			if list1.Val > list2.Val {
				curr.Next = &ListNode{Val : list2.Val}
				list2 = list2.Next
			}else{
				curr.Next = &ListNode{Val : list1.Val}
				list1 = list1.Next
			}
		}else if list1 != nil {
			curr.Next = &ListNode{Val : list1.Val}
			list1 = list1.Next
		}else {
			curr.Next = &ListNode{Val : list2.Val}
			list2 = list2.Next
		}

		curr = curr.Next
	}


	return newNode.Next
}

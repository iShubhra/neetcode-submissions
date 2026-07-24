/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	prev := &ListNode{Next : head}
	node := &ListNode{Next : reverse(prev)}
	list := node

	for list != nil && n > 1 {
		n--
		list = list.Next
	}
	list.Next = list.Next.Next

	return reverse(node.Next).Next
}

func reverse(head *ListNode) *ListNode {
	prev := &ListNode{}
	prev = nil
	for head != nil {
		next := head.Next
		head.Next = prev
		prev = head
		head = next
	}

	return prev
}
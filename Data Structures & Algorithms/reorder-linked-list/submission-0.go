/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func reorderList(head *ListNode) {
	if head == nil || head.Next == nil {
		return
	}

	fast := head.Next.Next
	slow := head

	for fast != nil && fast.Next != nil {
		fast = fast.Next.Next
		slow = slow.Next
	}

	node := reverse(slow.Next)
	slow.Next = nil

	for head != nil {
		headNext := head.Next
		nodeNext := node.Next
		head.Next = node
		if headNext == nil {
			return
		}
		node.Next = headNext
		head = headNext
		node = nodeNext
	}
}

func reverse(head *ListNode) *ListNode {
	var prev *ListNode = nil
	for head != nil {
		next := head.Next
		head.Next = prev
		prev = head
		head = next
	}

	return prev
}

func print(head *ListNode) {
	for head != nil {
		fmt.Print(head.Val)
		head = head.Next
	}

	fmt.Println()
}
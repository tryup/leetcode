/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil{
		return head
	}
	p := head
	pre := head
	next := head.Next
	for ; next != nil; {
		if pre.Val == next.Val {
			pre.Next = nil
		}else {
			pre.Next = next
			pre = next

		}
		next = next.Next
	}
	return p
}

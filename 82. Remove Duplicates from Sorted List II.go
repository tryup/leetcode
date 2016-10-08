package main
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

type ListNode struct {
	Val int
	Next *ListNode
}

func deleteDuplicates(head *ListNode) *ListNode {

	var newHead,preNode,nowNode *ListNode

	for{

	}

	return newHead
}

func AddNode(root *ListNode,val int)(*ListNode){
	root.Next = &ListNode{val,nil}
	return root.Next
}

func Disp(root* ListNode){
	for {
		if( root !=nil ){
			println( root.Val)
			root = root.Next
		}
	}
}
func main(){
	root := &ListNode{}
	root.Val =1
	AddNode(AddNode(AddNode(AddNode(root,2),3),4),5)
	Disp(root)

}

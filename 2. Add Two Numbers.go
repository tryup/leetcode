func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {

	nl1 := l1
	nl2 := l2
	var n1l,n2l *ListNode
	l:=0
	for ;l1!=nil||l2!=nil;{
		if l1==nil{
			nl1=nl2
		}
		vl1 :=0
		vl2 :=0
		n1l = l1
		n2l = l2
		if l1!=nil {
			vl1=l1.Val
		}
		if l2!=nil{
			vl2=l2.Val
		}

		vc := vl1+vl2+l
		if vc>=10{
			l=1
			vc-=10
		}else {
			l=0
		}

		if l1!=nil {
			l1.Val=vc
			l1 = l1.Next
		}
		if l2!=nil{
			l2.Val=vc
			l2 = l2.Next
		}
		if l1==nil && l2==nil {
			if l == 1{
				if n1l == nil{
					n1l =n2l
				}
				r := &ListNode{}
				r.Val=1
				n1l.Next = r
			}
			break
		}
	}
	return nl1
}

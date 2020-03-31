package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	var pHead *ListNode = nil
	if nil == l1 {
		return l2
	}
	if nil == l2 {
		return l1
	}
	if l1.Val > l2.Val {
		pHead = l2
		l2 = l2.Next
	} else {
		pHead = l1
		l1 = l1.Next
	}
	cur := pHead
	for l1 != nil && l2 != nil {
		if l1.Val > l2.Val {
			cur.Next = l2
			l2 = l2.Next
		} else {
			cur.Next = l1
			l1 = l1.Next
		}
		cur = cur.Next
	}
	if nil == l1 {
		cur.Next = l2
	}
	if nil == l2 {
		cur.Next = l1
	}
	return pHead
}

func mergeTwoLists2(l1 *ListNode, l2 *ListNode) *ListNode {
	if nil == l1 {
		return l2
	}
	if nil == l2 {
		return l1
	}

	if l2.Val > l1.Val {
		l1.Next = mergeTwoLists(l1.Next, l2)
		return l1
	} else {
		l2.Next = mergeTwoLists(l1, l2.Next)
		return l2
	}

}

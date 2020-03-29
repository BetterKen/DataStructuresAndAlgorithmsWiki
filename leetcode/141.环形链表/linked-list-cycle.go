package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func hasCycle(head *ListNode) bool {
	var fastP, slowP *ListNode
	fastP = head
	slowP = head
	for fastP != nil && fastP.Next != nil && fastP.Next.Next != nil {
		fastP = fastP.Next.Next
		slowP = slowP.Next
		if fastP == slowP {
			return true
		}
	}
	return false
}

package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func detectCycle(head *ListNode) *ListNode {
	fastP, slowP := head, head
	for fastP != nil && fastP.Next != nil && fastP.Next.Next != nil {
		fastP = fastP.Next.Next
		slowP = slowP.Next
		if slowP == fastP {
			fastP = head
			for {
				if slowP == fastP {
					return fastP
				}
				fastP = fastP.Next
				slowP = slowP.Next
			}
		}
	}
	return nil
}

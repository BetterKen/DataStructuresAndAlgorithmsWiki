package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	var dummy ListNode
	pHead := &dummy
	pre := pHead
	pHead.Next = head
	start := pre
	end := pre
	for end != nil {
		for i := 0; i < k && end != nil; i++ {
			end = end.Next
		}
		if nil == end {
			return pHead.Next
		}

		start = pre.Next
		next := end.Next
		end.Next = nil
		pre.Next = reverseList(start)
		start.Next = next
		pre = start
		end = start
	}
	return pHead.Next
}

func reverseList(head *ListNode) *ListNode {
	var pre *ListNode
	cur := head
	for cur != nil {
		next := cur.Next
		cur.Next = pre
		pre = cur
		cur = next
	}
	return pre
}

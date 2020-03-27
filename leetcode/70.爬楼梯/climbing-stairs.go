package main

func climbStairs(n int) int {
	f1, f2 := 1, 2
	var f3 int
	if 1 == n {
		f3 = f1
		return f3
	}
	if 2 == n {
		f3 = f2
		return f3
	}
	for i := 3; i <= n; i++ {
		f3 = f1 + f2
		f1 = f2
		f2 = f3
	}
	return f3
}

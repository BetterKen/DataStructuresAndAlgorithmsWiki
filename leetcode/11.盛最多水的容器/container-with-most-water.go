package main

func maxArea(height []int) int {
	var max int = 0
	head := 0
	tail := len(height) - 1
	for head < tail {
		var area int
		if height[head] > height[tail] {
			area = height[tail] * (tail - head)
			tail--
		} else {
			area = height[head] * (tail - head)
			head++
		}

		if area > max {
			max = area
		}
	}
	return max
}

package main

func moveZeroes(nums []int) {
	for i, j := 0, 0; i < len(nums); i++ {
		if 0 != nums[i] {
			nums[j] = nums[i]
			if i != j {
				nums[i] = 0
			}
			j++
		}
	}
}

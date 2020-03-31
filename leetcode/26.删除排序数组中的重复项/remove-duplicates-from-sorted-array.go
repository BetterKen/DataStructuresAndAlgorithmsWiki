package main

func removeDuplicates(nums []int) int {
	slowP := 0
	for cur := 1; cur < len(nums); cur++ {
		if nums[slowP] != nums[cur] {
			slowP++
			nums[slowP] = nums[cur]
		}
	}
	return slowP + 1
}

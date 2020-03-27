package main

func twoSum(nums []int, target int) []int {
	var result = []int{0, 0}
	length := len(nums)
	for i := 0; i < length-1; i++ {
		for j := i + 1; j < length; j++ {
			if target == nums[i]+nums[j] {
				result[0] = i
				result[1] = j
			}
		}
	}
	return result
}

func twoSum2(nums []int, target int) []int {
	var result = []int{0, 0}
	var length = len(nums)
	var hashMap = make(map[int]int)

	for i := 0; i < length; i++ {
		diff := target - nums[i]
		v, ok := hashMap[diff]
		if ok {
			result[0] = i
			result[1] = v
		} else {
			hashMap[nums[i]] = i
		}
	}
	return result
}

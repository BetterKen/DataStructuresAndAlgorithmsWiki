package main

import (
	"sort"
)

func threeSum(nums []int) [][]int {
	var result [][]int
	length := len(nums)
	sort.Ints(nums)
	for i := 0; i < length-2; i++ {
		head := i + 1
		tail := length - 1
		for head < tail {
			if 0 == nums[head]+nums[tail]+nums[i] {
				var tmp []int
				tmp = append(tmp, nums[head], nums[tail], nums[i])
				result = append(result, tmp)
				for nums[head] == nums[head+1] && head+1 < tail {
					head++
				}
				head++
				for nums[tail] == nums[tail-1] && tail-1 > head {
					tail--
				}
				tail--
			} else if 0 > nums[head]+nums[tail]+nums[i] {
				head++
			} else {
				tail--
			}
		}
		for nums[i] == nums[i+1] && i < length-2 {
			i++
		}
	}
	return result
}

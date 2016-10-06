func productExceptSelf(nums []int) []int {

	l := len(nums)
	if l <= 1 {
		return []int{}
	}
	left := make([]int, len(nums))
	right := make([]int, len(nums))

	left[0] = nums[0]
	right[l - 1] = nums[l - 1]
	for i := 0; i < l - 1; i++ {
		left[i + 1] = left[i] * nums[i + 1];
		right[l - i - 1 - 1] = right[l - i - 1] * nums[l - 1 - i - 1];
	}
	ans := make([]int, len(nums))
	for i := 0; i < l; i++ {
		if i == 0 {
			ans[i] = right[i + 1];
		} else if i == l - 1 {
			ans[i] = left[i - 1];
		} else {
			ans[i] = left[i - 1] * right[i + 1]
		}
	}
	return ans
}

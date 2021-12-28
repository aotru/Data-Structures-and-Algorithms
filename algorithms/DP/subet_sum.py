def subset_sum(nums: list, target: int) -> bool:
    n = len(nums)
    memo = [([False] * (target + 1)) for i in range(n + 1)]
    
    # memo[n][x] = can we get a subset that adds up to x with the first n numbers in nums
    
    # Base Case 1: x = 0
    for i in range(n + 1):
        memo[i][0] = True
    # Base Case 2: n = 0, x != 0
    for i in range(1, target + 1):
        memo[0][i] = False
    
    for i in range(1, n + 1):
        for curr_target in range(1, target + 1):
            memo[i][curr_target] = memo[i - 1][curr_target]
            if curr_target >= nums[i - 1]:
                memo[i][curr_target] = memo[i - 1][curr_target] or memo[i - 1][curr_target - nums[i - 1]]
    return memo[n][target]
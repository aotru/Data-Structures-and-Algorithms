# Given an integer array nums, find number of distinct contiguous subarrays with 
# at most k odd elements. Two subarrays are distinct when they have at least one different element.

def k_odd(nums: list, k : int) -> int:
    n = len(nums)
    subarrays = set()
    total = 0

    for i in range(n):
        subarray = str()
        odd_count = 0
        for j in range(i, n):
            odd_count += nums[j] % 2
            subarray += str(nums[j])

            if odd_count <= k:
                if subarray not in subarrays:
                    total += 1
                    subarrays.add(subarray)
            else:
                break
    return total

    
print(k_odd([3, 2, 3, 4], 1))
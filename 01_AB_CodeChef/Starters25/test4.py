def findPairs(nums, k):
    nums.sort()
    n = len(nums)
    ans = []
    for i in range(n - 1):
        for j in range(i + 1, n):
            if nums[j] - nums[i] == k:
                tup = (nums[j], nums[i])
                if tup not in ans:
                    ans.append(tup)
    return len(((ans)))

print(findPairs([3, 1, 4, 1, 5], 2))
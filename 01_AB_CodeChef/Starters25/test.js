var findPairs = function (nums, k) {
	nums.sort((a, b) => a - b);
	let n = nums.length;
	let ans = [];
	for (let i = 0; i < n - 1; i++) {
		for (let j = i + 1; j < n; j++) {
			if (nums[j] - nums[i] == k) {
				ans.push([nums[j], nums[i]]);
			}
		}
	}
	console.log([...new Set(ans)]);
	return [...new Set(ans)].length;
};

console.log(findPairs([1, 3, 1, 5, 4], 2));


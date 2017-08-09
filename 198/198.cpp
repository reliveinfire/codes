#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
#if 1
class Solution {
	public:
	int rob(vector<int>& nums){
		int size = nums.size();
		if (size == 0)
			return 0;
		return helper(nums, size);
	}
	int helper(vector<int>& nums, int curr){
		if (curr == 0)
			return 0;
		if (curr == 1)
			return nums[0];
		return max( nums[curr-1] + helper(nums, curr-2),
				helper(nums, curr -1));
	}
};
#else
class Solution {
	public:
	int rob(vector<int>& nums){
		int size = nums.size();
		if (size == 0)
			return 0;
		vector<int> dp(size+1, 0);
		dp[1] = nums[0];

		for (int i = 2 ; i <= size ; i++){
			int target = nums[i-1];
			dp[i] = max(target + dp[i-2], dp[i-1]);
		}
		return dp[size];
	}
};
#endif

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	vector<int> ret_vec;
	int A[] = {2,4,3,5};
	genVector(da, A);
	Solution sol;
	ret = sol.rob(da);
	cout << ret << "\n";

	return 0;
}

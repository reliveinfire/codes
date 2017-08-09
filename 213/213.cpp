#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
#if 0
class Solution {
	public:
	int result;
	int rob(vector<int>& nums){
		int size = nums.size();
		result = 0;
		if (size == 0)
			return 0;
		vector<bool> table(size, false);
		helper(nums, 0, table, 0);
		return result;	
	}
	void helper(vector<int>& nums, int start, vector<bool> table, int value){
		result = max(value, result);
		if (start >= nums.size()){
			return;
		}
		for (int i = start ; i < nums.size() ; i++){
			if (i==0 && !table[i]){
				table[i] = true;
				helper(nums, i + 2, table, value + nums[i]);
				table[i] = false;
			} else if ( i < nums.size() - 1 && !table[i] && !table[i-1]) {
				table[i] = true;
				helper(nums, i + 2, table, value + nums[i]);
				table[i] = false;
			} else if (!table[i-1] && !table[0]){
				table[i] = true;
				helper(nums, i + 2, table, value + nums[i]);
				table[i] = false;
			}
		}
		return;
	}
		
};
#else
class Solution {
	public:
	int rob(vector<int>& nums){
		int size = nums.size();
		if (size == 0)
			return 0;
		if (size == 1)
			return nums[0];
		vector<int> dp(size+1, 0);
		dp[1] = nums[0];
		for (int i = 2 ; i <size ; i++){
			int target = nums[i-1];
			dp[i] = max(target + dp[i-2], dp[i-1]);
		}
		int noLast = dp[size-1];
		fill(dp.begin(), dp.end(), 0);
		dp[2] = nums[1];
		for (int i = 3 ; i <=size ; i++){
			int target = nums[i-1];
			dp[i] = max(target + dp[i-2], dp[i-1]);
		}
		int noFirst = dp[size];
		return max(noLast, noFirst);
	}
};
#endif

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	vector<int> ret_vec;
	//int A[] = {2,4,3,5};
	//int A[] = {10,200,20,30,300};
	int A[] = {1,1,1};
	//int A[] = {2,1};
	genVector(da, A);
	Solution sol;
	ret = sol.rob(da);
	cout << ret << "\n";

	return 0;
}

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
	bool PredictTheWinner(vector<int>& nums){
		int size = nums.size();
		int sum = 0;
		if (size == 1)
			return true;

		for (int i = 0 ; i < size ; i++)
			sum += nums[i];
		int my = helper(nums, 0, size -1);
		int other = sum - my;

		return my >= other;
	}

	int helper(vector<int>& nums, int l, int r){
		if (l==r)
			return nums[l];
		if (l+1 == r)
			return max(nums[l],nums[r]);
		
		int tmp = max(nums[l] + min(helper(nums, l+2,r), helper(nums, l+1, r-1)),
			      nums[r] + min(helper(nums, l+1,r-1), helper(nums, l, r-2)));
		return tmp;
	}
};
#else
class Solution {
	public:
	bool PredictTheWinner(vector<int>& nums){
		int size = nums.size();
		int sum = 0;
		if (size == 1)
			return true;
		vector< vector<int> > dp( size, vector<int>(size,0));

		for (int j = 0 ; j < size ; j++){
			for(int i = j ; i >= 0 ; i--){
				if(i == j)
					dp[i][j] = nums[i];
				else if(i+1 == j)
					dp[i][j] = max(nums[i], nums[j]);
				else {
				dp[i][j] = max( nums[i] + min(dp[i+2][j], dp[i+1][j-1]),	
						nums[j] + min(dp[i+1][j-1], dp[i][j-2]));
				}
			}
		}

		for (int i = 0 ; i < size ; i++)
			sum += nums[i];
		int my = dp[0][size-1];
		int other = sum - my;

		return my >= other;
	}

};
#endif

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	vector<int> ret_vec;
	int A[] = {1,5,2};
	int B[] = {1,5,233,7};
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	ret = sol.PredictTheWinner(da);
	cout << ret << "\n";
	ret = sol.PredictTheWinner(db);
	cout << ret << "\n";

	return 0;
}

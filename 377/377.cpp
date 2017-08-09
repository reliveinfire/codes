#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <unordered_set>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	int combinationSum4(vector<int>& nums, int target){
		vector<int> tt(target+1, -1);
		return helper(nums, target, tt);
	}

	int helper(vector<int>& nums, int target, vector<int>& tt){
		int ret = 0;
		if (target == 0)
			return 1;
		if (tt[target]!= -1)
			return tt[target];
		for (int i = 0 ; i < nums.size() ; i++){
			if (target - nums[i] >= 0)
				ret += helper(nums, target - nums[i], tt);
		}
		tt[target] = ret;
		return tt[target];
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret = sol.
	ret_vec = sol.
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

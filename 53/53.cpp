#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	int maxSubArray(vector<int>& nums){
		int ret = 0;
		if (nums.empty())
			return ret;
		int lm, gm;
		for (int i = 0 ; i < nums.size() ; i++){
			if (i == 0){
				lm = nums[i];
				gm = nums[i];
			} else {
				lm += nums[i];
				lm = max(lm, nums[i]);

				gm = max(lm,gm);
			}
		}
		return gm;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {-2,1,-3,4,-1,2,1,-5,4};
	int B[] = {1,2,3};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	int ret;
	ret = sol.maxSubArray(da);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

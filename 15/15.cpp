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
	vector<vector<int>> threeSum(vector<int>& nums){
		vector<vector<int>> ans;
		if (nums.size() < 3)
			return ans;
		sort(nums.begin(), nums.end());
		for (int i = 0 ; i + 2 < nums.size() ; i++){
			if (i ==0 || nums[i]!= nums[i-1]){
				vector<int> tmp(3);
				int lo = i+1, hi = nums.size() - 1;
				while (lo < hi){
					int total = nums[i] + nums[lo] + nums[hi];
					if (total == 0){
						tmp[0] = nums[i];
						tmp[1] = nums[lo];
						tmp[2] = nums[hi];
						lo++;
						hi--;
						while(lo<nums.size() && nums[lo-1]==nums[lo]) lo++;
						while(hi>lo          && nums[hi-1]==nums[hi]) hi--;
					} else if (total>0){
						hi--;
					} else
						lo++;
				}
			}
		}
		return ans;
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

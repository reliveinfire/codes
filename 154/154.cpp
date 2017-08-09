#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	int findMin(vector<int>& nums){
		int lo = 0, hi = nums.size() - 1;
		while(lo < hi){
			if (nums[lo]==nums[hi])
				hi = hi -1;
			else {
				if (nums[lo] < nums[hi])
					return nums[lo];
				int mid = lo + (hi-lo)/2;
				if (nums[mid]>=nums[lo])
					lo = mid + 1;
				else
					hi = mid;
			}
		}
		return nums[lo];
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {5,4};
	int B[] = {5,4,5,5,5,5,5};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	vector<int> ret_vec;
	int ret;
//	ret = sol.findMin(da);
	cout << ret << "\n";
	ret = sol.findMin(db);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

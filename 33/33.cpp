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
	 int search(vector<int>& nums, int target) {
	 	if (nums.empty())
			return -1;
	 	int lo = 0, hi = nums.size() - 1;
		while(lo < hi){
			int mid = lo + (hi-lo)/2;
			if (nums[mid] == target)
				return mid;
			if (nums[mid] >= nums[lo]){
				if (target <= nums[mid] && target >= nums[lo])
					hi = mid - 1;
				else
					lo = mid + 1;
			} else {
				if (target > nums[mid] && target <= nums[hi])
					lo = mid + 1;
				else
					hi = mid - 1;
			}
		}
		if (nums[lo] == target)
			return lo;
		else 
			return -1;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {8,7};
	genVector(da, A);
	int ret;
	Solution sol;
	ret = sol.search(da,8);
	cout << ret << "\n";

	cout <<endl;

	return 0;
}

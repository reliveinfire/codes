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
	int findPeakElement(vector<int>& nums){
		int lo = 0, hi = nums.size() - 1;
		while (lo < hi){
			int mid = lo  + (hi - lo) / 2;
			if (mid == 0){
				if (nums[mid] > nums[mid+1])
					return mid;
				else
					lo = mid + 1;
			} else {
				if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
					return mid;
				else if (nums[mid] < nums[mid+1])
					lo = mid+1;
				else if (nums[mid] < nums[mid-1])
					hi = mid-1;
			}
		}
		return lo;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {1,2,3,9,6,4,3,2};
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

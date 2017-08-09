#include <iostream>
#include <string>
#include <map>
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
	int singleNonDuplicate(vector<int>& nums){
		if (nums.size() ==1)
			return nums[0];
		int lo = 0 , hi = nums.size() - 1;
		while (lo<hi){
			int mid = lo + (hi-lo)/2;
			if (nums[mid]!= nums[mid+1] && nums[mid] != nums[mid-1])
				return nums[mid];

			if (nums[mid] == nums[mid+1]){
				hi = mid - 1;
			} else if (nums[mid]==nums[mid-1]){
				lo = mid + 1;
			}
			if (lo==hi)
				return nums[lo];
		}
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

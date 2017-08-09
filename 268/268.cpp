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
	int missingNumber(vector<int>& nums){
		int size = 0;
		int zero;
		for (int i = 0 ; i < nums.size() ; i++){
			int tt = nums[i];
			if (tt < 0)
			 	tt = 0 - tt;
			if (tt == nums.size())
				size = -1;
			else {
			nums[tt] = 0 - nums[tt];
			}
		}
		if (size == 0)
			return nums.size();
		else {
			for (int i = 0 ; i < nums.size() ; i++){
				if (nums[i] > 0)
					return i;
				if (nums[i] == 0)
					zero = i;
			}
			return zero;
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

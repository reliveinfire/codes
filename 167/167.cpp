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
	vector<int> twoSum(vector<int>& nums, int target){
		vector<int> ans(2);
		for (int i = 0 ; i < nums.size() ; i++){
			int lo = i+1, hi = nums.size() - 1;
			int tmp = target - nums[i];
			while(lo<hi){
				int mid = lo + (hi-lo) /2;
				if (nums[mid] >= tmp){
					hi = mid;
				} else
					lo = mid + 1;
			}
			cout << i << ":" << lo << endl;
			if (nums[lo] == tmp){
				ans[0] = i;
				ans[1] = lo;
				break;
			}
		}
		return ans;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {-3,3,4,90};
	int B[] = {1,2,3};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret_vec = sol.twoSum(da, 0);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

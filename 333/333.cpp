#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
using namespace std;
#include "../helpers.cpp"
vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};

struct State{
	int  count;
	long  tmax;
	long  tmin;
}
class Solution {
	public:
	int maxSubtreeCount(TreeNode* root){
		State ll = helper(root->left);
		State rr = helper(root->right);
		return max(ll.count, rr.count);
	}
	State helper(TreeNode* node){
		if (node==NULL)
			return {0, INT_MIN, INT_MAX};
		State ls = helper(node->left);
		State rs = helper(node->right);
		if (node->val >= ls.tmax && node->val <= rs.tmin)
			return {1 + ls.count + rs.count, max(node->val, rs.max), min(node->val, ls.min)};
		else
			return {max(ls.count, rs.count), INT_MAX+1, INT_MIN-1};
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	string tre("1,#,3,2,#,#,4,#,5,#,#");
	Codec cc;
	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
	Solution sol;
	int ret;
	ret = sol.
	auto ret_vec = sol.
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

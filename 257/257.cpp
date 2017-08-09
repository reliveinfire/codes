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
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	vector<string> binaryTreePaths(TreeNode* root){
		return helper(root);
	}
	vector<string> helper(TreeNode* node){
		vector<string> left;
		vector<string> right;
		vector<string> ret;
		if (node==NULL)
			return {};
		if (node->right == NULL && node->left ==NULL)
			return {to_string(node->val)};
		else {
			right = helper(node->right);
			left = helper(node->left);
		}
		string tmp;
		for (string ss : left){
			tmp = to_string(node->val) + string("->") + ss;
			ret.push_back(tmp);
		}
		tmp.clear();
		for (string ss : right){
			tmp = to_string(node->val) + string("->") + ss;
			ret.push_back(tmp);
		}
		return ret;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
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

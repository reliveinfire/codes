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
	map<TreeNode*, int> table;
	int maxPathSum(TreeNode* root){
		int ans = INT_MIN;
		traversal(root, ans);
		return ans;
	}

	void traversal(TreeNode* node, int& ans, )
	{
		if (node == NULL)
			return;
		int rMax = 0, lMax = 0;
		maxPath(node->left, 0, lMax);
		maxPath(node->right, 0, rMax);
		int a = rMax + node->val;
		int b = lMax + node->val;
		int c = rMax + lMax + node->val;
		ans = max(ans, node->val);
		if (node->left == NULL){
			ans = max(a, ans);
		} else if (node->right == NULL){
			ans = max(b,ans);
		} else {
			int tmax = max(a,max(b,c));
			ans = max(ans, tmax);
		}
		traversal(node->left, ans);
		traversal(node->right, ans);
		return;
	}

	int maxPath(TreeNode* node, int pre)
	{
		if (node == NULL)
			return;
		int curr = pre + node->val;
		int mm = max()
		allMax = max(curr, allMax);
		maxPath(node->left, curr, allMax);
		maxPath(node->right, curr, allMax);
		return;
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
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	ret = sol.maxPathSum(root);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

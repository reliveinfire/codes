#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		TreeNode* convertBST(TreeNode* root) {
			if (root == NULL)
				return root;
			helper(root, 0);
			return root;
		}

		void helper(TreeNode* root, int parent)
		{
			if (root == NULL)
				return;
			int sumR = sum(root->right);
			root->val = root->val + parent +sumR;

			helper(root->right, parent);
			helper(root->left, root->val);
			return;
		}

		int sum(TreeNode* root)
		{
			if (root==NULL)
				return 0;
			return root->val + sum(root->right) + sum(root->left);
		}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	vector<int> ret_vec;
	int A[] = {1,2,3};
	genVector(da, A);
	Solution sol;

	return 0;
}

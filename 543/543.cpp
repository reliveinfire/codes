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
		int ret;
		int diameterOfBinaryTree(TreeNode* root) {
			ret = 0;
			maxDepth(root);
			return ret;
		}

		int maxDepth(TreeNode* root){
			if (root == NULL)
				return 0;
			int left = maxDepth(root->left);
			int right = maxDepth(root->right);
			ret = max(left + right, ret);

			return 1 + max(left, right);
		}

};
int main()
{
	int ret;
	int test[] = {1,2,3};
	vector<int> data(test, test + sizeof(test)/sizeof(test[0]));
	Solution sol;

	return 0;
}

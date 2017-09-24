#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        bool isValidBST(TreeNode* root){
		return helper(root, (long)INT_MIN -1, (long)INT_MAX+1);
        }
	bool helper(TreeNode* node, long bmin, long bmax){
		if (node==NULL)
			return true;
		bool left = helper(node->left, bmin, node->val);
		bool right = helper(node->right, node->val, bmax);
		if (left && right && bmin < node->val && node->val < bmax)
			return true;
		return false;
	}
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	Solution sol;
	int ret;
	ret = sol.isValidBST(root);
	cout << ret << "\n";


	return 0;
}

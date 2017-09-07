#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        TreeNode* trimBST(TreeNode* root, int L, int R){
		return helper(root, L, R);
        }
	TreeNode* helper(TreeNode* node, int L, int R){
		if (node==NULL)
			return NULL;
		if (node->val < L)
			return helper(node->right, L, R);
		else if (node->val>R)
			return helper(node->left, L, R);
		node->left = helper(node->left, L, R);
		node->right = helper(node->right, L, R);
		return node;
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

#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        int maxPathSum(TreeNode* root){
		int res = INT_MIN;
		findmax(root, res);
		return res;
        }
	int findmax(TreeNode* node, int& res){
		if (node==NULL)
			return 0;
		int ret = INT_MIN;
		int ll = findmax(node->left, res);
		int rr = findmax(node->right, res);
		ret = max(ret, node->val);
		ret = max(ret, node->val+ll);
		ret = max(ret, node->val+rr);
		res = max(res, node->val);
		res = max(res, node->val+ll+rr);
		res = max(res, node->val+ll);
		res = max(res, node->val+rr);
		return ret;
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

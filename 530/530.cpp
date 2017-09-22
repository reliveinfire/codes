#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        int getMinimumDifference(TreeNode* root){
		int pre = -1;
		int ans = INT_MAX;
		traversal(root, pre, ans);
		return ans;
        }
	void traversal(TreeNode* node, int& pre, int& ans){
		if (node==NULL)
			return;
		traversal(node->left, pre, ans);
		if (pre>=0){
			ans = min(ans, abs(node->val - pre));
		}
		pre = node->val;
		traversal(node->right, pre, ans);
		return;
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

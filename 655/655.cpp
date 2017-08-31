#include "../helpers.cpp"

class Solution {
        public:
        vector<vector<string>> printTree(TreeNode* root){
		int hh = getHeight(root);
		int row = 1;
		for (int i = 2 ; i <= hh ; i++)
			row = row*2 + 1;
		vector<vector<string>> res(hh, vector<string>(row, ""));
		helper(root, 0, row-1, 0, res);
		return res;
        }
	int getHeight(TreeNode* node){
		if (node==NULL)
			return 0;
		int lh = getHeight(node->left);
		int rh = getHeight(node->right);
		return 1  + max(lh, rh);
	}
	void helper(TreeNode* node, int ll, int rr, int hh, vector<vector<string>>& res){
		if (node==NULL)
			return;
		res[hh][(ll+rr)/2] = to_string(node->val);
		helper(node->left, ll, (ll+rr)/2-1, hh+1, res);
		helper(node->right, (ll+rr)/2+1, rr, hh+1, res);
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

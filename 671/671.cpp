#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
	struct State {
		int fmin;
		int smin;
	};
        int findSecondMinimumValue(TreeNode* root){
		State ret = helper(root);
		if (ret.smin==INT_MAX)
			return -1;
		return ret.smin;
        }
	State helper(TreeNode* node){
		if (!node->left && !node->right)
			return {node->val, INT_MAX};
		else {
			State left = helper(node->left);
			State right = helper(node->right);
			vector<int> vv = {left.fmin, left.smin, right.fmin, right.smin};
			sort(vv.begin(), vv.end());
			int i = 0;
			for (; i < vv.size() ; i++)
				if (vv[i] != node->val)
					break;
			if (i==vv.size())
				return {node->val, INT_MAX};
			else
				return {node->val, vv[i]};
		}
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

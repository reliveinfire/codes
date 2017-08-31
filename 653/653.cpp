#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        bool findTarget(TreeNode* root, int k) {
		unordered_set<int> tb;
		return helper(root, k, tb);
        }

	bool helper(TreeNode* node, int target, unordered_set<int>& tb)
	{
		if (node==NULL)
			return false;
		int diff = target - node->val;
		if (tb.count(diff)!= 0)
			return true;
		tb.insert(node->val);
		return helper(node->left, target, tb) || helper(node->right, target, tb);
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

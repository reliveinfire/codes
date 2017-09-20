#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
	private:
	struct State{
		TreeNode* ans;
		int node;
	};
        public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
		State res = helper(root, p, q);
		return res.ans;
        }
	State helper(TreeNode* node, TreeNode* p, TreeNode* q){
		if (node==NULL){
			return {NULL, 0};
		}
		State left = helper(node->left, p, q);
		State right = helper(node->right, p, q);
		if (left.ans)
			return {left.ans, 2};
		if (right.ans)
			return {right.ans, 2};
		if (left.node>0 && right.node >0){
			return {node, 2};
		} else if (left.node > 0 || right.node >0){
			if (node==p || node == q)
				return {node, 2};
			else
				return {NULL, 1};
		} else {
			if (node== p || node == q)
				return {NULL, 1};
		}
		return {NULL, 0};
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

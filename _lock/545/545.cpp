#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        vector<int> boundaryTree(TreeNode* root){
		vector<int> res;
		vector<int> ri;
		int hasleaf = 0;
		if (!root)
			return {};
		if (!root->left && !root->right)
			return {root->val};
		if (root->left)
			leftBound(node, hasleaf, res);
		else {
			hasleaf = 1;
			res.push_back(node->val);
			leftBound(root, hasleaf, res);
		}
		if (root->right){
			hasleaf = 0;
			rightBound(root, hasleaf, res);
		}
		if (!ri.empty()){
			for (int i = ri.size() - 1; i >0; i--)
				res.push_back(ri[i]);
		}
		return res;
        }
	private:
		void leftBound(TreeNode* node, int& hasleaf, vector<int>& res){
			if (node->left==NULL && node->right==NULL){
				hasleaf = 1;
				res.push_back(node->val);
			}
			if (!hasleft)
				res.push_back(node->val);
			if (node->left)
				leftBound(node->left, hasleaf, res);
			if (node->right)
				leftBound(node->right, hasleaf, res);
			return;
		}
		void rightBound(TreeNode* node, int& hasleaf, vector<int>& ri){
			if (node->left==NULL && node->right==NULL){
				hasleft = 1;
			}
			if (!hasleaf)
				res.push_back(node->val);
			if (!hasleaf && node->right)
				rightBound(node->right, hasleaf, ri);
			if (!hasleaf && node->left)
				rightBound(node->left, hasleaf, ri);
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

#include "../../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        vector<vector<int>> findleaf(TreeNode* root){
		vector<vector<int>> res;
		vector<int> rm;
		while(remove(root, rm, NULL, 0)){
			res.push_back(rm);
			rm.clear();
		}
		res.push_back(rm);
		return res;
        }
	bool remove(TreeNode* node, vector<int>& rm, TreeNode* parent, int left){
		if (node->left==NULL && node->right==NULL){
			if (parent){
				if (left)
					parent->left = NULL;
				else
					parent->right = NULL;
			}
			rm.push_back(node->val);
			return false;
		}
		if (node->right)
			remove(node->right, rm, node, 0);
		if (node->left)
			remove(node->left, rm, node, 1);
		return true;
	}
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	string tre("1,2,4,#,#,5,#,#,3,#,#");
	Codec cc;
	TreeNode* node = cc.deserialize(tre);
	Solution sol;
	vector<vector<int>> ret_vec = sol.findleaf(node);
	
	for (vector<int> vv : ret_vec){
		for (int i : vv)
			cout << i << " ";
		cout << endl;
	}

	return 0;
}

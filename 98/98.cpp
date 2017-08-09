#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	bool isValidBST(TreeNode* root){
		if (!root)
			return true;
		return helper(root);
	}

	bool helper(TreeNode* root){
		bool ll,rr;
		TreeNode* idx;
		if (root->left){
			idx = root->left;
			while(idx){
				if (idx->val >= root->val)
					return false;
				idx = idx->right;
			}
			ll = helper(root->left);
		}
		if (root->right){
			idx = root->right;
			while(idx){
				if (idx->val <= root->val)
					return false;
				idx = idx->left;
			}
			rr = helper(root->right);
		}

		if (root->left && root->right)
			return ll && rr;
		else if(root->left)
			return ll;
		else  if (root->right)
			return rr;
		else
			return true;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	int ret;
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

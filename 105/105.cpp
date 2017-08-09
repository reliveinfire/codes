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
	int preidx;
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
		preidx = 0;
		return build(preorder, inorder, 0, inorder.size() - 1);
	}

	TreeNode* build(vector<int>& preorder, vector<int>& inorder, int ll, int rr){
		if (ll > rr)
			return NULL;
		TreeNode* node = new TreeNode(preorder[preidx]);
		preidx++;
		if (ll == rr)
			return node;
		int pos;
		for (int i = 0 ; i < inorder.size() ; i++){
			if (inorder[i] == node->val){
				pos = i;
				break;
			}
		}
		node->left = build(preorder, inorder, ll, pos - 1);
		node->right = build(preorder, inorder, pos + 1, rr);
		return node;
	}
};

void traversal(TreeNode* root){
	if (root == NULL)
		return;
	traversal(root->left);
	traversal(root->right);
	cout << " " << root->val;
	return;
}
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {1,2,4,5,3,6};
	int B[] = {4,2,5,1,6,3};
	int C[] = {4,5,2,6,3,1};
	genVector(preorder, A);
	genVector(inorder, B);
	genVector(postorder, B);
	Solution sol;
	TreeNode* ret;
	ret = sol.buildTree(preorder, inorder);
	traversal(ret);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

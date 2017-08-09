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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
		preidx = postorder.size() - 1;
		return build(postorder, inorder, 0, inorder.size() - 1);
	}

	TreeNode* build(vector<int>& postorder, vector<int>& inorder, int ll, int rr){
		if (ll > rr)
			return NULL;
		TreeNode* node = new TreeNode(postorder[preidx]);
		preidx--;
		if (ll == rr)
			return node;
		int pos;
		for (int i = 0 ; i < inorder.size() ; i++){
			if (inorder[i] == node->val){
				pos = i;
				break;
			}
		}
		node->right = build(postorder, inorder, pos + 1, rr);
		node->left = build(postorder, inorder, ll, pos - 1);
		return node;
	}
};

void traversal(TreeNode* root){
	if (root == NULL)
		return;
	cout << " " << root->val;
	traversal(root->left);
	traversal(root->right);
	return;
}
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
#if 0
	int A[] = {1,2,4,5,3,6};
	int B[] = {4,2,5,1,6,3};
	int C[] = {4,5,2,6,3,1};
#else
	int B[] = {1,2,3,4};
	int C[] = {1,3,4,2};
#endif
//	genVector(preorder, A);
	genVector(inorder, B);
	genVector(postorder, C);
	Solution sol;
	TreeNode* ret;
	ret = sol.buildTree(postorder, inorder);
	traversal(ret);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

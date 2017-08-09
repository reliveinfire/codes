#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> ans;
void inorder_travel(TreeNode* node){
	if (node==NULL)
		return;
	cout << node->val << " ";
	inorder_travel(node->left);
//	ans.push_back(node->val);
	inorder_travel(node->right);
	return;
}
void iter_in_order(TreeNode* root)
{
	stack<TreeNode*> st;
	TreeNode* idx = root;
	while(true){
		if (idx != NULL){
			cout << idx->val << " ";
			st.push(idx);
			idx = idx->left;
		} else {
			if (st.empty())
				break;
			else{
				idx = st.top();
				st.pop();
			//	ans.push_back(idx->val);
				idx= idx->right;
			}
		}
	}
}

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	TreeNode* idx = root->left;
	idx->left = new TreeNode(4);
	idx->right = new TreeNode(5);
	idx = root->right;
	idx->left = new TreeNode(6);
	idx->right = new TreeNode(7);
	inorder_travel(root);
	cout <<endl;
	iter_in_order(root);

	return 0;
}

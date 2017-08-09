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

class Solution {
	public:
	bool found;
	int kthSmallest(TreeNode* root, int k){
		int ans;	
		found = false;
	}

	void traversal(TreeNode* root, int& k, int& ans){
		if (root==NULL)
			return;
		if (found)
			return;
		traversal(root->left, k, ans);
		k = k -1;
		if (k==0){
			ans = root->val;
			found = true;
		}
		traversal(root->right, k, ans);
	}
};
void inorder_travel(TreeNode* node){
	if (node==NULL)
		return;
	travel(node->left);
	ans.push_back(node->val);
	travel(node->right);
	return;
}
vector<int> ans;
void iter_in_order(TreeNode* root)
{
	stack<TreeNode*> st;
	TreeNode* idx = root;
	while(true){
		if (idx != NULL){
			st.push(idx);
			idx = idx->left;
		} else {
			if (st.empty())
				break;
			else{
				idx = st.top();
				st.pop();
				ans.push_back(idx->val);
				idx= idx->right;
			}
		}
	}
}

void postorder_travel(TreeNode* node){
	if (node==NULL)
		return;
	travel(node->left);
	travel(node->right);
	ans.push_back(node->val);
	return;
}
void iter_post_order(TreeNode* root){
	stack<TreeNode*> st;
	TreeNode* idx = root;
	while(true){
		if(idx!=NULL){
			ans.push_back(idx->val);
			idx = idx->left;
		} else {
			idx = st.top();st.pop();
			idx= idx->right;
		}
	}
}

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret = sol.
	ret_vec = sol.
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

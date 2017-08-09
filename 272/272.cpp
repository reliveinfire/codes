#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	vector<int> closestKValues(TreeNode* root, int target, int k){
		TreeNode* idx = root;
		int lm = INT_MAX;
		stack<TreeNode*> pre;
		stack<TreeNode*> suc;
		int small;
		vector<int> ans;
		while(idx!=NULL){
			if (abs(idx->val - target) < lm){
				lm = abs(idx->val - target);
				small = idx->val;	
			}
			if (idx->val - target > 0)
				idx = idx->left;
			else if (idx->val - target < 0)
				idx = idx->right;
			else
				break;
		}
		idx = root;
		while(idx->val != small){
			pre.push(idx);
			suc.push(idx);
			if (small > idx->val)
				idx = idx->right;
			else if (small < idx->val)
				idx = idx->left;
		}
		pre.push(idx);
		suc.push(idx);
		TreeNode* pn = idx;
		TreeNode* sn = idx;
		ans.push_back(idx->val);
		pn = preNode(pn, pre);
//		sn = sucNode(sn, suc);
		while (ans.size() < k){
			int pVal=INT_MAX, sVal=INT_MAX;
			if (pn)
				pVal = pn->val;
			if (sn)
				sVal = sn->val;
			if (abs(pVal -target) < abs(sVal-target)){
				ans.push_back(pVal);
				pn = preNode(pn,pre);
			} else {
				ans.push_back(sVal);
				//sn = sucNode(sn, suc);
			}
		}
		return ans;
	}
	TreeNode* preNode(TreeNode* curr, stack<TreeNode*>& pre){
		if (curr->left){
			curr = curr->left;
			while(curr->right){
				pre.push(curr);
				curr = curr->right;
			}
		} else {
			while(!pre.empty()){
				if (curr == pre.top()->right){
					curr = pre.top();
					pre.pop();
					return curr;
				} else {
					curr = pre.top();
					pre.pop();
				}
			}
			return NULL;
		}
		return curr;
	}
#if 0
	TreeNode* sucNode(TreeNode* curr, stack<TreeNode*>& suc){
		if (curr->right){
			curr = curr->right;
			suc.push(curr);
			while(curr->left){
				curr = curr->left;
				suc.push(curr);
			}
		} else {
			while(!suc.empty()){
				if (curr == suc.top()->left){
					curr = suc.top();
					return curr;
				} else {
					curr = suc.top();
					suc.pop();
				}
			}
			return NULL;
		}
		return curr;
	}
#else
	void sucNode(stack<TreeNode*>& suc){
		TreeNode* curr = suc.top();
		if (curr->right){
			curr = curr->right;
			suc.push(curr);
			while(curr->left){
				curr = curr->left;
				suc.push(curr);
			}
		} else {
			suc.pop();
			while(!suc.empty()){
				if (curr == suc.top()->left){
					return;
				} else {
					curr = suc.top();
					suc.pop();
				}
			}
		}
	}
#endif
};

TreeNode* genBST(vector<int>& pre)
{
	int idx = 0;
	TreeNode* node = new TreeNode(pre[idx++]);
	stack<TreeNode*> st;
	st.push(node);
	while(idx < pre.size()){
		if (pre[idx] < st.top()->val){
			st.top()->left = new TreeNode(pre[idx++]);
			st.push(st.top()->left);
		} else {
			TreeNode* tmp;
			while(!st.empty() && st.top()->val < pre[idx]){
				tmp = st.top();
				st.pop();
			}
			tmp->right = new TreeNode(pre[idx++]);
			st.push(tmp->right);
		}
	}
	return node;
}

void inorderTraversal(TreeNode* node){
	if (node == NULL)
		return;
	inorderTraversal(node->left);
	cout << node->val << " ";
	inorderTraversal(node->right);
}

void inorderIter(TreeNode* node)
{
	TreeNode* idx = node;
	stack<TreeNode*> st;
	while(true){
		if (idx!=NULL){
			st.push(idx);
			idx = idx->left;
		} else {
			if (st.empty())
				break;
			idx = st.top();
			st.pop();
			cout << idx->val << " ";
			idx = idx->right;
		}
	}
}

void preorderTraversal(TreeNode* node){
	if (node == NULL)
		return;
	cout << node->val << " ";
	preorderTraversal(node->left);
	preorderTraversal(node->right);
}
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	//BST pre-order
	vector<int> A = {100,50, 40, 80, 60, 200, 150, 180, 250};
	TreeNode* root = genBST(A);
	inorderTraversal(root);
	cout << endl;
	preorderTraversal(root);
	cout << endl;
	inorderIter(root);
	cout << endl;
	Solution sol;
	stack<TreeNode*> st;
	st.push(root);
	st.push(root->left);
	st.push(root->left->right);
	while(!st.empty()){
		cout << st.top()->val << " ";
		sol.sucNode(st);
	}
	vector<int> ret_vec;
	int ret;

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
} 

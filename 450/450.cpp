#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
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
	TreeNode* deleteNode(TreeNode* root, int key) {
		TreeNode* dummy = new TreeNode(key==0?1:0);
		dummy->left = root;
		helper(dummy, key);
		return dummy->left;
	}

	bool checkChild(TreeNode* root, int key){
		if (root == NULL)
			return false;
		if (root->val == key)
			return true;
		else
			return false;
	}

	void mydelete(TreeNode* child, TreeNode* parent, int isLeft){
		TreeNode* idx;
		TreeNode* next;
		if (child->left == NULL && child->right == NULL){
			if (isLeft){
				parent->left = NULL;
			} else {
				parent->right = NULL;
			}
		} else if (child->left != NULL){
			next = child->left;
			idx = next;
			while(idx->right != NULL)
				idx = idx->right;
			if (isLeft){
				parent->left = next;
			} else {
				parent->right = next;
			}
			idx->right = child->right;
		} else {
			next = child->right;
			idx = next;
			while(idx->left != NULL)
				idx = idx->left;
			if (isLeft){
				parent->left = next;
			} else {
				parent->right = next;
			}
			idx->left = child->left;
		}
		return;	
	}

	void helper(TreeNode* root, int key){
		if (root == NULL)
			return;
		while(checkChild(root->left, key)) {
			mydelete(root->left, root, 1);
		}
		
		while(checkChild(root->right, key)) {
			mydelete(root->right, root, 0);
		}
		helper(root->left, key);
		helper(root->right, key);
		return;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
#define case2
#ifdef case1
	TreeNode* node = new TreeNode(5);
	TreeNode* add;
	TreeNode* idx = node;

	add = new TreeNode(3);
	idx->left = add;
	add = new TreeNode(6);
	idx->right = add;

	idx = idx->left;
	
	add = new TreeNode(2);
	idx->left = add;
	add = new TreeNode(4);
	idx->right = add;

	idx = node->right;
	add = new TreeNode(7);
	idx->right = add;

	int key = 6;
	//int key = 3;
#endif
#ifdef case2
	TreeNode* node = new TreeNode(2);
	TreeNode* add;
	TreeNode* idx = node;
	add = new TreeNode(1);
	idx->left = add;
	int key = 2;
#endif
	
	
	Solution sol;
	idx = sol.deleteNode(node, key);
	cout << idx->val;
	

	return 0;
}

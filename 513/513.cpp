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
	int rowMax;
	int llest;
	int ret;
	public:
	int findBottomLeftValue(TreeNode* root) {
		rowMax = -1;
		llest = INT_MAX;
		ret = 0;
		helper(root, 0, 0);

		return ret; 
	}

	void helper(TreeNode* root, int row, int left)
	{
		if (root == NULL)
			return;
		if (row > rowMax){
			rowMax = row;
			llest = left;
			ret = root->val;
		}
		if (row == rowMax){
			if (left < llest){
				llest = left;
				ret = root->val;
			}
		}
		helper(root->left, row + 1, left -1);
		helper(root->right, row + 1, left+1);
		return;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	TreeNode* root = new TreeNode(1);

	TreeNode* idx;
	TreeNode* tmp;
	tmp = new TreeNode(2);
	root->left = tmp;
	
	tmp = new TreeNode(3);
	root->right = tmp;

	idx = root->left;
	tmp = new TreeNode(4);
	idx->left = tmp;
	
	idx = root->right;
	tmp = new TreeNode(5);
	idx->left = tmp;
	tmp = new TreeNode(6);
	idx->right = tmp;

	idx = idx->left;
	//tmp = new TreeNode(7);
	//idx->left = tmp;

	vector<int> ret_vec;
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	ret = sol.findBottomLeftValue(root);
	cout << ret << "\n";

	return 0;
}

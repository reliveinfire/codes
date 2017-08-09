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
	int closestValue(TreeNode* root, double target){
		int ans;
		int lm = INT_MAX;
#if 0
		helper(root, target, ans);
#else
		TreeNode* idx = root;
		while(idx!=NULL){
			if (abs(target - idx->val) < lm){
				lm = abs(target - idx->val);
				ans = idx->val;
			}
			if (idx->val - target > 0){
				idx = idx->left;
			} else if (idx->val - target < 0){
				idx = idx->right;
			}
		}
#endif
		return ans;
	}
	void helper(TreeNode* node, double target, int& ans, int& lm){
		if (node==NULL)
			return;
		if(abs(target - node->val) < lm){
			lm = abs(target - node->Val);
			ans = node->val;
		}
		if (node->val > target){
			helper(node->left, target, ans, lm);
		} else if (node->val < target){
			helper(node->right, target, ans, lm);
		} 
		return;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
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

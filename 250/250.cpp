#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <unordered_set>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	int countUnivalSubtrees(TreeNode* root){
		int ans = 0;
		isuni(root, ans);
		return ans;
	}
//寫得有點不好? 比較亂嗎?
	bool isuni(TreeNode* node, int& ans){
		if (!node->left && !node->right){
			ans++;
			return true;
		}else if (node->left && !node->right) {
			if (node->left->val == node->val && isuni(node->left, ans)){
				ans++;
				return true;
			}
		}else if (node->right && !node->left){
			if (node->right->val == node->val && isuni(node->right, ans)){
				ans++;
				ret = true;
			}
		} else {
			if (node->left->val == node->val && isuni(node->left, ans)
			    && (node->right->val == node->val && isuni(node->right, ans)){
			    	ans++;
			    return true;
			   }
		}
		return flase;
	}
};

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

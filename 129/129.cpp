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
	int sumNumbers(TreeNode* root){
		int ans = 0;
		if (root==NULL)
			return 0;
		traversal(root, 0, ans);
		return ans;
	}
	void traversal(TreeNode* node, int curr, int& ans)
	{
		if (node->left == NULL && node->right==NULL){
			 ans += curr * 10 + node->val;
			 cout << ans << endl;
			 return;
		}
		if (node->left!=NULL)
				traversal(node->left, curr*10 + node->val, ans);
		if (node->right!=NULL)
				traversal(node->right, curr*10 + node->val, ans);
		return;
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
	TreeNode* root = new TreeNode(9);
	vector<int> ret_vec;
	int ret;
	ret = sol.sumNumbers(root);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

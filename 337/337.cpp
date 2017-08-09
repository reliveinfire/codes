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
	map<TreeNode*, int> dp_rob;
	map<TreeNode*, int> dp_nrob;
	int rob(TreeNode* root){
		return max(helper(root,1), helper(root, 0));
	}
	int helper(TreeNode* node, int rob)
	{
		if (node==NULL)
			return 0;
		if (rob){
			if (dp_rob.find(node)!=dp_rob.end())
				return dp_rob[node];
		} else {
			if (dp_nrob.find(node)!=dp_nrob.end())
				return dp_nrob[node];

		}
		if (rob){
			dp_rob[node] = node->val + helper(node->left, 0) + helper(node->right, 0);
			return dp_rob[node];
		} else{
			int curMax = INT_MIN;
			int a = helper(node->left, 1) + helper(node->right, 1);
			curMax = max(a, curMax);
			int b = helper(node->left, 0) + helper(node->right, 1);
			curMax = max(b, curMax);
			int c = helper(node->left, 1) + helper(node->right, 0);
			curMax = max(c, curMax);
			int d = helper(node->left, 0) + helper(node->right, 0);
			curMax = max(d, curMax);
			dp_nrob[node] = curMax;
			return dp_nrob[node];
		}
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

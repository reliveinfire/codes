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
		vector<int> inorderTraversal(TreeNode* root) {
			stack<TreeNode*> ss;
			vector<int> result;
			if (root==NULL)
				return result;
			pushall(root, ss);

			while(!ss.empty()){
				TreeNode* tmp = ss.top();
				cout << tmp->val<< endl;
				result.push_back(tmp->val);
				ss.pop();
				pushall(tmp->right, ss);
			}
			return result;

		}
		void pushall(TreeNode* node, stack<TreeNode*>& ss){
			while(node!=NULL){
				ss.push(node);
				node = node->left;
			}
			return;
		}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	string sa("godding");
	string sb("gd");
	TreeNode* root = new TreeNode(1);
	TreeNode* idx = root;
	root->right = new TreeNode(2);
	idx = root->right;
	idx->left = new TreeNode(3);
	int ret;
	Solution sol;
	ret_vec = sol.inorderTraversal(root);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

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
	vector<int> largestValues(TreeNode* root){
		vector<int> result;
		queue<TreeNode*> qq;
		int count = 1;
		int lc = 0;
		int mm = INT_MIN;

		qq.push(root);

		while(!qq.empty()){
			TreeNode* tmp = qq.front();
			qq.pop();
			if (tmp->val > mm)
				mm = tmp->val;
			count--;

			if (tmp->left) {
				qq.push(tmp->left);
				lc++;
			}
			if (tmp->right) {
				qq.push(tmp->right);
				lc++;
			}
			if (count == 0){
				count = lc;
				lc = 0;
				result.push_back(mm);
				mm = INT_MIN;
			}
		}
		return result;
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
	tmp = new TreeNode(7);
	idx->left = tmp;

	vector<int> ret_vec;
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	ret_vec = sol.largestValues(root);
	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " "<<endl;

	return 0;
}

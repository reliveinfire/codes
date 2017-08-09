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
		vector<vector<int>> pathSum(TreeNode* root, int sum) {
			vector<vector<int> > result;
			vector<int> st;
			if (root == NULL)
				return result;
			helper(root, sum , result, st);
			return result;
		}
		
		void helper(TreeNode* root, int sum, vector<vector<int> >& result, vector<int>& st){
			st.push_back(root->val);
			sum -= root->val;

			if (root->left == NULL && root->right == NULL &&
					sum == 0){
				result.push_back(st);
				st.
				return;	
			}
			if (root->left)
				helper(root->left, sum, result,st);
			if (root->left)
				helper(root->right, sum, result, st);
			st.pop_back();
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
	vector<int> ret_vec;
	int ret;
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

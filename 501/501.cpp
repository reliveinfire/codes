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
	int tmax;
	vector<int> findMode(TreeNode* root){
		vector<int> result;
		map<int,int> tt;
		tmax = 0;
		helper(root, tt);

		map<int,int>::iterator iter;
		for (iter = tt.begin() ; iter!= tt.end() ; iter++){
			if (iter->second == tmax)	
				result.push_back(iter->first);
		}
		return result;	
	}

	void helper(TreeNode* root, map<int,int>& tt)
	{
		if (root==NULL)
			return;
		int tmp;
		map<int,int>::iterator iter;
		iter = tt.find(root->val);
		if (iter == tt.end()){
			tt[root->val] = 1;
			tmp = 1;
		} else {
			tmp = iter->second;
			tmp++;
			tt.erase(iter);
			tt[root->val] = tmp;
		}
		if (tmp > tmax)
			tmax = tmp;
		helper(root->left, tt);
		helper(root->right, tt);
		return;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	TreeNode* root = new TreeNode(1);
	TreeNode* idx = root;

	root->right = new TreeNode(2);
	idx = idx->right;
	idx->left = new TreeNode(2);
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	ret_vec = sol.findMode(root);
//	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

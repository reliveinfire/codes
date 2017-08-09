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
#include "../helpers.cpp"
vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};


class Solution {
	public:
	vector<vector<int>> virtialBT(TreeNode* root){
		map<int, vector<int>> ret;
		vector<vector<int>> ans;
		traversal(0, root, ret);
		for (auto iter = ret.begin() ; iter != ret.end() ; iter++)
			ans.push_back(iter->second);
		return ans;
	}

	void traversal(int level, TreeNode* node, map<int, vector<int>>& ret){
		if (node == NULL)
			return;
		ret[level].push_back(node->val);
		traversal(level - 1, node->left, ret);
		traversal(level + 1, node->right, ret);
		return;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	string tre("3,9,4,#,#,5,#,#,20,2,#,#,7,#,#");
	Codec cc;
	TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
	Solution sol;
	vector<vector<int>> ret_vec;
	int ret;
	ret_vec = sol.virtialBT(node);
	for (vector<int> row : ret_vec){
		for (int item : row){
			cout << item << ",";
		}
	cout << endl;
	}

	return 0;
}

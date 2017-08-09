#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
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
	map<int,int> table;
	vector<int> findFrequentTreeSum(TreeNode* root){
		vector<int> result;
		int count = 0;
		map<int,int>::iterator iter;
		if (root == NULL)
			return result;
		helper(root);

		for(iter = table.begin() ; iter != table.end() ; iter++){
			count = max(count, iter->second);
		}
		
		for(iter = table.begin() ; iter != table.end() ; iter++){
			if (iter->second == count)
				result.push_back(iter->first);
		}
		
		return result;
	}

	int helper(TreeNode* root){
		if (root == NULL)
			return 0;
		int l_sum = helper(root->left);
		int r_sum = helper(root->right);

		int sum = root->val + l_sum + r_sum;
		map<int,int>::iterator iter;

		iter = table.find(sum);
		if (iter == table.end()){
			table[sum] = 1;
		} else {
			int tmp = iter->second;
			tmp++;
			table.erase(sum);
			table[sum] = tmp;
		}

		return sum;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret;
	TreeNode* node = new TreeNode(5);
	TreeNode* add;
	TreeNode* idx;

	node->left = new TreeNode(2);
	node->right = new TreeNode(-5);
	Solution sol;
	ret = sol.findFrequentTreeSum(node);
	for (int i = 0 ; i < ret.size() ; i++){
		cout << ret[i] << " ";
	}

	return 0;
}

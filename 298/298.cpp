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
	int longestConsecutive(TreeNode* root){
		int ans, max = INT_MIN;
		helper(root, max, ans);
		return ans;
	}

	int helper(TreeNode* node, int& max,int& ans){
		int left = 1, right = 1;
		if (node->left){
			left = helper(node->left, max, ans);
			if (node->left->val + 1 == node->val){
				left = left+1;
				if (left > max){
					max = left;
					ans = node->val;
				}
			} else 
				left = 1;
		}
		if (node->right){
			right = helper(node->right, max, ans);
			if (node->right->val + 1 == node->val){
				right = right+1;
				if (right > max){
					max = right;
					ans = node->val;
				}
			} else 
				right = 1;
		}
		return std::max(left,right);
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	string treA("1,#,3,2,#,#,4,#,5,#,#");
	Codec cc;
	TreeNode* rootA= cc.deserialize(treA);
	Solution sol;
	int ret;
	ret = sol.longestConsecutive(rootA);;
	cout << ret << "\n";


	return 0;
}

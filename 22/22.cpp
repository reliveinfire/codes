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
	vector<string> generateParenthesis(int n){
		string ss;
		vector<string> ans;
		helper(string(""), 0, 0, n, ans);
		return ans;
	}
	void helper(string str, int left, int right, int n, vector<string>& ans)
	{
		if (left == n && right == n){
			ans.push_back(str);
			return;
		}

		if (left < n){
			helper(str + string("("), left + 1, right, n, ans);
		}

		if (right < left){
			helper(str + string(")"), left, right + 1, n, ans);
		}
		return;	
	}

};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	Solution sol;
	vector<string> ret_vec;
	ret_vec = sol.generateParenthesis(3);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << endl;
	cout <<endl;

	return 0;
}

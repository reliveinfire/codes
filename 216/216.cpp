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
	vector<vector<int>> combinationSum3(int k, int n){
		vector<vector<int>> ans;
		if (k>9)
			return ans;
		vector<int> st;
		helper(1, k, n, st, ans);
		return ans;
	}
	void helper(int start, int count, int sum, vector<int>& st,vector<vector<int>>& ans){
		if (count == 0 && sum == 0){
			ans.push_back(st);
			return;
		}
		for (int i = start ; i <= 9 ; i++){
			st.push_back(i);
			helper(i+1, count - 1, sum - i, st, ans);
			st.pop_back();
		}
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
	ret = sol.
	ret_vec = sol.
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

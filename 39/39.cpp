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
	vector<vector<int>> combinationSum(vector<int>& cand, int target){
		vector<vector<int>> ans;
		if (cand.empty())
			return ans;
		vector<int> st;
//		helper2(cand, 0, target, st, ans);
		combine(cand, 0, 2, st, ans);
		return ans;
		
	}
	void helper(vector<int>& cand, int start, int sum, vector<int>& st, vector<vector<int>>& ans)
	{
		if (sum == 0){
			ans.push_back(st);
			return;
		}
		if (sum < 0)
			return;
		unordered_set<int> used;
		for (int i = start ; i < cand.size() ; i++){
			if (used.count(cand[i])== 0){
				used.insert(cand[i]);
				st.push_back(cand[i]);
				helper(cand, i+1, sum - cand[i], st, ans);
				st.pop_back();
			}
		}
		return;
	}
	void helper2(vector<int>& cand, int start, int sum, vector<int>& st, vector<vector<int>>& ans){
		ans.push_back(st);
		for (int i = start ; i < cand.size() ; i++){
			st.push_back(cand[i]);
			helper2(cand, i+1, sum, st, ans);
			st.pop_back();
		}
	}
	void combine(vector<int>& cand, int start, int count, vector<int>& st, vector<vector<int>>& ans){
		if (count == 0){
			ans.push_back(st);
			return;
		}
		for (int i = start ; i < cand.size() ; i++){
			st.push_back(cand[i]);
			combine(cand, i+1, count -1, st, ans);
			st.pop_back();
		}
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {2,3,6,7};
	genVector(da, A);
	Solution sol;
	vector<vector<int>> ret_vec;
	ret_vec = sol.combinationSum(da,7);

	for (int i = 0 ; i < ret_vec.size() ; i++){
		for (int j = 0 ; j < ret_vec[i].size() ; j++)
			cout << ret_vec[i][j] << " ";
		cout << endl;
	}
	cout <<endl;

	return 0;
}

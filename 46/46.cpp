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
	vector<vector<int> > ans;
	vector<vector<int>> permute(vector<int>& nums){
		if (nums.empty())
			return ans;
		vector<bool> visit(nums.size(), false);
		vector<int> st;
		helper(nums, st, visit);
		return ans;
	}

	void helper(vector<int>& nums, vector<int>& st, vector<bool>& visit){
		if (st.size() == nums.size()){
			ans.push_back(st);
			return;
		}
		for (int i = 0 ; i < nums.size() ; i++){
			if (!visit[i]){
				visit[i] = true;
				st.push_back(nums[i]);
				helper(nums, st, visit);
				st.pop_back();
				visit[i] = false;
			}
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

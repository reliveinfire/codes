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
	vector<vector<int>> getFactors(int n) {
		vector<int> st;
		vector<vector<int>> ans;
		helper(2, n, n, st, ans);
		return ans;
	}
	void helper(int start, int value, int orig, vector<int>& st, vector<vector<int>>& ans){
		if (value == 1)	{
			ans.push_back(st);
			return;
		}
		for (int i = start ; (i*2 <= orig) && (i<= value) ; i++){
			if (value % i==0){
				st.push_back(i);
				helper(i, value/i, orig, st, ans);
				st.pop_back();
			}
		}
		return;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	Solution sol;
	vector<vector<int>> ret_vec;
	ret_vec = sol.getFactors(8);
	
	for (vector<int> item : ret_vec){
		for (int i : item){
			cout << i << " ";
		}
		cout << endl;
	}
	cout <<endl;

	return 0;
}

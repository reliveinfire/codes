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
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	int minCost(vector<vector<int>>& costs){
		vector<vector<int>> dp(costs.size(), vector<int>(3));
		dp[0][0] = costs[0][0];
		dp[0][1] = costs[0][1];
		dp[0][2] = costs[0][2];
		for (int i = 1 ; i < costs.size() ; i++){
			dp[i][0] = costs[i][0] + min(dp[i-1][1], dp[i-1][2]);
			dp[i][1] = costs[i][1] + min(dp[i-1][0], dp[i-1][2]);
			dp[i][2] = costs[i][2] + min(dp[i-1][0], dp[i-1][1]);
		}
		return min(dp[costs.size()][0], min(dp[costs.size()][1], dp[costs.size()][2]));
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
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

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
	int minPathSum(vector<vector<int>>& grid){
		if (grid.empty())
			return 0;
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> dp(m, vector<int>(n,0));
		int sum = 0;
		for (int i = 0 ; i < n ; j++){
			sum += grid[0][i];
			dp[0][i] = sum;
		}
		for (int i = 0 ; i < m ; j++){
			sum += grid[i][0];
			dp[i][0] = sum;
		}
		for (int i = 1 ; i < m ; i++){
			for(int j = 0 ; j < n ; j++){
				dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
			}
		}
		return dp[m-1][n-1];
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

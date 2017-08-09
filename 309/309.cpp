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
	int maxProfit(vector<int>& prices){
		if (prices.empty())
			return 0;
		vector< vector<int> > dp(prices.size()+1, vector<int>(2));
		dp[0][0] = INT_MIN;
		dp[0][1] = 0;
		for (int i = 1 ; i <= prices.size() ; i++){
			if (i>=2)
				dp[i][0] = max(dp[i-2][1] - prices[i-1], dp[i-1][0]);
			else
				dp[i][0] = max(-prices[i-1], dp[i-1][0]);
			dp[i][1] = max(dp[i-1][0] + prices[i-1], dp[i-1][1]);
		}
		return dp[prices.size()][1];
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

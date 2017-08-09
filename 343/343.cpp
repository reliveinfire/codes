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
	int integerBreak(int n){
		vector<int> dp (n+1, 0);
		if (n==2) return 1;
		if (n==3) return 2;
		return helper(n, dp);
	}
	int helper(int n, vector<int>& dp){
		if (n == 2) return 2;
		if (n == 3) return 3;
		if (dp[n]!=0) 	return dp[n];

		int ans = 0;
		for (int i = 2 ; i <= n -2 ; i++ ){
			ans = max(ans, i* helper(n-i, dp));
		}
		dp[n] = ans;
		return dp[n];
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
	cout << sol.integerBreak(4) << endl;
	cout << sol.integerBreak(5) << endl;
	cout << sol.integerBreak(6) << endl;
	cout << sol.integerBreak(7) << endl;
	cout << sol.integerBreak(8) << endl;
	cout << sol.integerBreak(9) << endl;
	cout << sol.integerBreak(10) << endl;

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

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
		int maxProfit(int k, vector<int>& prices){
			if (prices.size() < 2)
				return 0;
			int profit = 0, pre = 0 , curr = 1, lm = 0;
			if (k > prices.size() / 2){
				int curMin = prices[0];
				for (int i = 1 ; i < prices.size() ; i++){
					if (prices[i] > prices[i-1])
						lm = prices[i] - curMin;
					else {
						curMin = prices[i];
						profit += lm;
						lm = 0;
					}
				}
				profit += lm;
				return profit;
			}
			vector<vector<int> > dp(2, vector<int>(2*k));
			for (int i = 0 ; i < 2 * k ; i++){
				if (i % 2 == 0)
					dp[0][i] = INT_MIN;
				else
					dp[0][i] = 0;
			}
			for (int i = 1 ; i <= prices.size() ; i++ ){
				for (int j = 0 ; j <  2 * k ; j++){
					if (j == 0)
						dp[curr][j] = max(-prices[i-1], dp[pre][j]);
					else {
						if (j%2 == 1)
							dp[curr][j] = max(dp[pre][j-1] + prices[i-1], dp[pre][j]);
						else
							dp[curr][j] = max(dp[pre][j-1] - prices[i-1], dp[pre][j]);
					}
					profit = max(profit, dp[curr][j]);
				}
				swap(curr, pre);
			}
			return profit;
		}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {1,2,4};
	int B[] = {1,2,3};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret = sol.maxProfit(2,da);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

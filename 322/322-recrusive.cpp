#include <iostream>
#include <vector>
#include <limits>
#include <climits>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
	public:
	int coinChange(vector<int>& coins, int amount){
		vector<vector<int> > dp(coins.size(), vector<int>(amount+1, -1));
		int ret =  helper(coins, amount, 0, 0, 0, dp);
		if (ret == INT_MAX)
			ret = -1;
		return ret;
	}

	int helper(vector<int>& coins, int amount, int curr, int maxcoin, int count,
			vector< vector<int> >& dp)
	{
		int ret1, ret2;
		if (amount < 0)
			return INT_MAX;
		if (amount == 0){
			return count;
		}
		if (curr > maxcoin)
			return INT_MAX;	
#if 1
		if (dp[curr][amount] != -1) {
		cout << "HIT maxcoin:" << maxcoin;
		cout << " amount:" << amount;
		cout << " dp:" << dp[maxcoin][amount] << endl;
//			return dp[curr][amount];
		}
#endif

		ret1 = helper(coins, amount - coins[curr], curr, maxcoin, count+1,dp);
		ret2 = helper(coins, amount, curr + 1, maxcoin, count,dp);
		if (dp[curr][amount]!= -1)
			dp[curr][amount] = min(dp[curr][amount], min(ret1,ret2));
		else
			dp[curr][amount] = min(ret1,ret2);
#if 1
		cout << " maxcoin:" << curr;
		cout << " amount:" << amount;
		cout << " dp:" << dp[maxcoin][amount] << endl;
#endif
		return dp[curr][amount];
	}
};


#define genVector(data, array) vector<int> data(array, array + sizeof(array)/ sizeof(array[0]));
int main()
{
	string sa("abc");
	string sb("bbc");
	string sc("ccc");
	int A[] = {1,2,5};
	int B[] = {2,5,10,1};
	genVector(da, A);
	genVector(db, B);

	Solution sol;
//	cout << sol.coinChange(da, 11);
	cout << endl;
	cout << sol.coinChange(db, 27);
	cout << endl;
	
	return 0;
}

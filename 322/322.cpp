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
		vector<vector<int> > dp(coins.size()+1, vector<int>(amount+1, amount+1));
		
		for (int i = 0 ; i <= coins.size() ; i++ )
			dp[i][0] = 0;

		for (int i = 1 ; i <= coins.size() ; i++){
			for (int j = 1 ; j <= amount ; j++){
				int target = coins[i-1];
				if (j >= target)
					dp[i][j] = min(dp[i-1][j], dp[i][j-target] + 1);
				else
					dp[i][j] = dp[i-1][j];
			}
		}
		if (dp[coins.size()][amount] == amount+1)
			return -1;
		else
			return dp[coins.size()][amount];
	
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
	cout << sol.coinChange(da, 11);
	cout << endl;
	cout << sol.coinChange(db, 27);
	cout << endl;
	
	return 0;
}

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
class Solution {
	public:
	int climbStairs(int n){
		vector<int> dp(n+1,0);
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3 ; i <= n ; i++){
			dp[i] = dp[i-1] + dp[i-2];
		}
		return dp[n];
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	vector<int> ret_vec;
	Solution sol;
	cout <<  sol.climbStairs(2) << endl;
	cout <<  sol.climbStairs(3) << endl;

	return 0;
}

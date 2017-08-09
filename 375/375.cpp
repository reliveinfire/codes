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
	int getMoneyAmount(int n){
		vector< vector<int> > dp(n + 1, vector<int>(n+1, 0));
		int x, tmp, i, j;
		int res;
		for (j = 2 ; j <=n ; j++){
			for (i = j ; i >=1; i--) {
				res = INT_MAX;
				if (i == j )
					dp[i][j] = 0;
				else if ( i + 1 == j)
					dp[i][j] = i;
				else {
					for (int k = i+1 ; k < j ; k++){
						// 選k 之後, 哪邊會付出比較多!
						tmp = k + max (dp[i][k-1], dp[k+1][j]);
						localMin = min(localMin, tmp);
					}
					dp[i][j] = localMin;
				}
			}
		}
		return dp[1][n];
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	int A[] = {1,2,3};
	genVector(da, A);
	Solution sol;
	ret = sol.getMoneyAmount(4);
	cout << ret << "\n";
	return 0;
}

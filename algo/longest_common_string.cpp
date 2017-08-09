#include <iostream>
#include <string>
#include <map>
using namespace std;
class Solution
{
	public:
		int LCS(string A, string B)
		{
			int m = A.size();
			int n = B.size();
			int ret_max;
			//int dp[501][501] = {0};
			if (m == 0)
				return n;
			if (n == 0)
				return m;

			for (int i = 1 ; i < m + 1 ; i++) {
				for (int j = 1 ; j < n + 1 ; j++){
					if (A[i - 1] == B[j - 1])
						dp[i][j] = dp[i-1][j-1] + 1;
					else
						dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
			return m - dp[m][n] + n - dp[m][n];
		}
};

int main()
{
	int ret;
	string A("2579312");
	string B("35328");
	Solution sol;
	
	ret = sol.LCS(A,B);
	cout << "LCS count:" << ret << "\n";
	
	string C("A");
	string D("AB");
	ret = sol.LCS(C,D);
	cout << "LCS count:" << ret << "\n";
	return 0;

}

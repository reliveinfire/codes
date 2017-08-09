#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
#if 0
class Solution {
	public:
	int minDistance(string word1, string word2){
		//if (word1.size() == 0 && word2.size()==0)
		//	return 0;
		return helper(word1, word2, word1.size(), word2.size());
	}

	int helper(string word1, string word2, int m, int n){
		if (m == 0)
			return n;
		if (n == 0)
			return m;
		if (word1[m-1] == word2[n-1])
			return helper(word1, word2, m-1, n-1);
		int tmp = helper(word1,word2, m-1, n-1);
		    tmp = min(tmp, helper(word1,word2, m-1, n));
		    tmp = min(tmp, helper(word1,word2, m, n-1));
		return 1+ tmp;
	}
};
#else
class Solution {
	public:
	int minDistance(string word1, string word2){
		//if (word1.size() == 0 && word2.size()==0)
		//	return 0;
		return helper(word1, word2, word1.size(), word2.size());
	}

	int helper(string word1, string word2, int m , int n)
	{
		vector< vector<int> > dp(m+1, vector<int>(n+1,0));

		for (int i = 0 ; i <= m ; i++){
			dp[i][0] = i;
		}
		
		for (int i = 0 ; i <= n ; i++){
			dp[0][i] = i;
		}

		for(int i = 1 ; i <=m ; i++){
			for (int j = 1; j <=n ; j++){
				if (word1[i-1] == word2[j-1])
					dp[i][j] = dp[i-1][j-1];
				else
					dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
			}
		}
		return dp[m][n];
	}
};
#endif

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	string A("Zeil");
	string B("trials");
	Solution sol;
	ret = sol.minDistance(A,B);
	cout << ret << "\n";

	return 0;
}

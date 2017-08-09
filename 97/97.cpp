#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;
class Solution {
	public:
	bool isInterleave(string s1, string s2, string s3){
		int n1 = s1.size();
		int n2 = s2.size();
		int n3 = s3.size();
		if (n3 != n1 + n2)
			return false;
		vector< vector< vector<int> > > dp(n1, vector< vector<int> >(n2, vector<int>(n3,-1)));

		return helper(s1,s2,s3,n1-1,n2-1,n3-1, dp);

	}

	bool helper(string s1, string s2, string s3, int n1, int n2, int n3, vector< vector< vector<int> > >& dp)
	{
		bool result;
		if (n1 == -1){
			return s2.substr(0, n2+1) == s3.substr(0,n3+1);
		}
		if (n2 == -1){
			return s1.substr(0, n1+1) == s3.substr(0,n3+1);
		}
		if (dp[n1][n2][n3] != -1)
			return dp[n1][n2][n3];
		if(s1[n1] == s3[n3] && s2[n2] == s3[n3]){
			result =  helper(s1,s2,s3,n1-1,n2,n3-1, dp) || helper(s1,s2,s3,n1,n2-1,n3-1,dp);
			if (result)
				dp[n1][n2][n3] = 1;
			else
				dp[n1][n2][n3] = 0;
			return result;
			
		} else if (s1[n1] == s3[n3]){
			result =  helper(s1,s2,s3,n1-1,n2,n3-1, dp);
			if (result)
				dp[n1][n2][n3] = 1;
			else
				dp[n1][n2][n3] = 0;
			return result;
		} else if (s2[n2] == s3[n3]){
			result =  helper(s1,s2,s3,n1,n2-1,n3-1,dp);
			if (result)
				dp[n1][n2][n3] = 1;
			else
				dp[n1][n2][n3] = 0;
			return result;
		} else {
			dp[n1][n2][n3] = 0;
			return false;
		}
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {1,2,3};
	int B[] = {1,2,3};
#define caseA
#ifdef caseA
	string sa("aabcc");
	string sb("dbbca");
	//string sc("aadbbcbcac");
	string sc("aadbbbaccc");
#endif
#ifdef caseB
	string sa("ab");
	string sb("b");
	string sc("abb");
#endif
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	bool ret;
	ret = sol.isInterleave(sa,sb,sc);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

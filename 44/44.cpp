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
	bool isMatch(string s, string p){
		vector<vector<int> > dp(s.size(), vector<int>(p.size(), -1));
		
		return helper(s,p, s.size()-1, p.size()-1, dp);
	}

	bool helper(string s, string p, int m, int n, vector<vector<int> >& dp)
	{
		if (m < 0 && n < 0)
			return true;
		if (m<0){
			while(n>=0){
				if (p[n]=='*'){
					n = n-1;
				} else 
					break;
			}
			if (n<0)
				return true;
			else
				return false;
		}

		if (n < 0 && m > 0){
			return false;
		}
		if (dp[m][n]!= -1){
			if (dp[m][n])
				return true;
			else
				return false;
		}
		bool ret, ret2;
		if (s[m] == p[n]){
			ret =  helper(s,p,m-1,n-1,dp);
			dp[m][n] = ret;
			return ret;
		} else {
			if (p[n]=='*'){
				ret = helper(s,p,m-1,n,dp);
				ret2 = helper(s,p,m,n-1,dp);
				dp[m][n] = ret || ret2;
				return ret || ret2;
			} else if (p[n] == '?'){
				ret= helper(s,p,m-1,n-1,dp);
				dp[m][n] = ret;
				return ret;
			} else 
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
//	string sa("aab");
//	string sb("c*a*b");
	string sa("a");
	string sb("");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	bool ret;
	ret = sol.isMatch(sa,sb);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

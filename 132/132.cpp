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
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#if 0
class Solution {
	public:
	int minCut(string s){
		vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
		int i;
		int result = 0;
		for (int j = 0 ; j < s.size() ; j++){
			for (i = j ; i >= 0 ; i--){
				if (i==j){
					dp[i][j] = 1;
				}else if (s[i] == s[j]){
					if (i+1==j)
						dp[i][j] = 1;
					else
						dp[i][j] = dp[i+1][j-1];
				} 
			}
		}
		return partCut(0, s.size()-1, dp);
	}

	int partCut(int ll, int rr, vector<vector<bool> >& dp){
		int curMax = 0;
		int mi, mj;
		if (ll==rr)
			return 0;
		for (int i = ll ; i <= rr ; i++){
			for (int j = i ; j <= rr ; j++){
				if (dp[i][j] == 1 ){
					if (j-i+1 > curMax){
						curMax = j-i+1;
						mi = i;
						mj = j;
					}
				}
			}
		}
	//	cout << ll << ":" << rr << endl;
	//	cout << mi << ":" << mj << endl;
		if (mi == ll && mj == rr)
			return 0;
		else if (mi== ll){
			return 1 + partCut(mj+1, rr, dp);
		} else if (mj == rr){
			return 1 + partCut(ll, mi-1, dp);
		} else {
			return 2 + partCut(ll, mi-1,dp) + partCut(mj+1,rr,dp);
		}
	}
};
#elseif 0
class Solution {
	public:
	int minCut(string s){
		vector<vector<int> > pal(s.size(), vector<int>(s.size(), -1));
		vector<vector<int> > dp(s.size(), vector<int>(s.size(),  -1));
		return helper(s, 0, s.size() - 1, pal, dp);
	}

	int helper(string s, int ll, int rr, vector<vector<int> >& pal, vector<vector<int> >& dp){
		if (pal[ll][rr]==-1){
			isPal(s,ll,rr,pal);
		}
		if (pal[ll][rr])
			return 0;
		if (dp[ll][rr]!=-1)
			return dp[ll][rr];
		int lm = INT_MAX, ret;
		for (int i = ll ; i <= rr -1 ; i++){
			ret = 1 + helper(s, ll, i, pal,dp) + helper(s, i+1, rr, pal,dp);
			lm = min(lm, ret);
		}
		dp[ll][rr] = lm;
		return lm;
	}

	bool isPal(string s, int ll, int rr, vector<vector<int> >& pal){
		if (ll == rr)
			return true;
		if (pal[ll][rr]!=-1)
			return pal[ll][rr];
		if (ll+1 == rr && s[ll] == s[rr]){
			pal[ll][rr] = 1;
		} else {
			string tmp = s.substr(ll, rr-ll+1);
			int mid = s.size() / 2;
			bool ret1 = checkPal(tmp, mid,mid);
			bool ret2 = checkPal(tmp, mid,mid+1);
			if (ret1||ret2)
				pal[ll][rr] = 1;
			else
				pal[ll][rr] = 0;
		}
		return pal[ll][rr];

	}
	bool checkPal(string s, int ll, int rr){
		while(ll>=0 && rr < s.size()){
			if (s[ll] == s[rr]){
				ll--;
				rr++;
			} else
				return false;
		}
		return true;
	}
};
#else
class Solution {
	public:
	int minCut(string s){
		vector<vector<bool> > pal(s.size(), vector<bool>(s.size(), false));
		vector<int> dp;
		// 初始值, 假若都沒有, ab -> min = 1, abc ->min =2
		for (int i = 0 ; i< s.size() ; i++){
		 	dp.push_back(i);
		}
		for (int j = 0 ; j < s.size() ; j++){
			for (int i = j ; i >= 0 ; i--){
				if (i==j){
					pal[i][j] = 1;
				}else if (s[i] == s[j]){
					if (i+1==j)
						pal[i][j] = 1;
					else
						pal[i][j] = pal[i+1][j-1];
				}
				if (pal[i][j]){
					if (i == 0)
						dp[j] = 0;
					else
						dp[j] = min(dp[i-1] + 1, dp[j]);
				}
			}
		}
		return dp[s.size()-1];
	}
};
#endif

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {1,2,3};
	int B[] = {1,2,3};
//	string sa("aaabba");
//	string sa("aaabba");
	//string sa("dg");
	string sb("aacbb");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret = sol.minCut("aaabba");
	//ret = sol.minCut("bba");
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

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
	string longestPalindrome(string s){
		vector< vector<int> > dp(s.size(), vector<int>(s.size(), -1));
		vector< vector<int> > state(s.size(), vector<int>(s.size(), -1));
		int size = lps(s, 0, s.size()-1, dp, state);
		string result;
		gen(s, 0, s.size()-1, state, result);
		string tmp(result);
		cout << size << endl;
		if (size% 2 == 0) {
			reverse(tmp.begin(), tmp.end());
			result += tmp;
		} else {
			tmp.erase(tmp.size()-1);
			reverse(tmp.begin(), tmp.end());
			result += tmp;
		}
		return result;
	}
	void gen(string& s, int ll, int rr, vector<vector<int> >& state, string& result){
		if (ll == rr){
			result += s[ll];
			return;
		}
		if (ll+1 == rr){
			if (s[ll] == s[rr]){
				result += s[rr];
			} else {
				result += s[ll];
			}
			return;
		}
		if (state[ll][rr] == 4){
			result += s[ll];
			gen(s, ll+1, rr - 1, state, result);
		} else if (state[ll][rr] == 3){
			gen(s, ll+1, rr, state, result);
		} else if (state[ll][rr] == 2){
			gen(s, ll, rr-1, state, result);
		} else {
			gen(s, ll+1, rr, state, result);
		}
		return;
	}

	int lps(string& s, int ll, int rr, vector<vector<int> >& dp, vector<vector<int> >& state){
		if (ll==rr){
			return 1;
		}
		if (ll+1 == rr){
			if (s[ll] == s[rr]){
				dp[ll][rr] = 2;
				state[ll][rr] = 4;
			} else {
				dp[ll][rr] = 1;
			}
			return dp[ll][rr];
		}
		if (dp[ll][rr]!= -1)
			return dp[ll][rr];

		if (s[ll] == s[rr]){
			dp[ll][rr] = 2 + lps(s, ll + 1, rr - 1, dp, state);
			state[ll][rr] = 4;
			return dp[ll][rr];
		} else if (lps(s, ll + 1, rr, dp, state) > lps(s, ll, rr - 1, dp, state)){
			dp[ll][rr] = lps(s,ll+1, rr, dp, state);
			state[ll][rr] = 3;
		} else if (lps(s, ll +1, rr, dp, state) < lps(s, ll, rr - 1, dp, state)){
			dp[ll][rr] = lps(s,ll, rr-1, dp, state);
			state[ll][rr] = 2;
		} else {
			dp[ll][rr] = lps(s,ll+1, rr, dp, state);
			state[ll][rr] = 1;
		}
		return dp[ll][rr];
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	string sa("bbbab");
	string sb("abcda");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	string ret = sol.longestPalindrome(sa);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

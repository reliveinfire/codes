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
	string shortestPalindrome(string s){
		vector< vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
		int i;
		if (s.empty())
			return s;
		for (int j = 0 ; j < s.size() ; j++){
			for (i = j ; i >= 0 ; i--){
				if (i == j){
					dp[i][j] = true;
				} else if (i+1 == j){
					if(s[i] == s[j])
						dp[i][j] = true;
				} else {
					if (dp[i+1][j-1]&& s[i]==s[j])
						dp[i][j] = true;
				}
			}
		}
		for (i = s.size() - 1 ; i>=0; i--){
			if(dp[0][i] == true)
				break;
		}
		string tmp(s.begin()+i+1,s.end());
		reverse(tmp.begin(), tmp.end());
		return tmp + s;
		
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	string sa("aacecaa");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	string ret;
	ret = sol.shortestPalindrome(sa);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

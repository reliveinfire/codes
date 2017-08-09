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
		vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
		int max_i = 0, max_j = 0;
		int lm = 0, i , j;
		for (j = 0 ; j < s.size() ; j++){
			for (i = j ; i >= 0 ; i--){
				if (i==j) {
					dp[i][j] = true;
				}
				else if (i+1 == j && s[i] == s[j]){
					dp[i][j] = true;
				} else {
					if (dp[i+1][j-1] && s[i] == s[j]){
						dp[i][j] = true;
					}
				}
				if (dp[i][j] && j - i + 1 > lm){
					lm = j - i + 1;
					max_i = i;
					max_j = j;
				}
			}
		}
		return s.substr(max_i, lm);
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	string sa("babb");
	string sb("abcda");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	
	string ret;
	ret = sol.longestPalindrome(sb);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

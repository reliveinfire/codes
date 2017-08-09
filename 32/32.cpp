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
#if 1
class Solution {
	public:
		int longestValidParentheses(string s){
			vector<int> dp(s.size(), 0);
			int curMax = 0;
			for (int i = 0 ; i < s.size() ; i++){
				if (s[i] == '(')
					continue;
				else {
					if (i==0)
						continue;
					if (s[i-1] == '('){
						if (i-2 < 0)
							dp[i] = 2;
						else
							dp[i] = dp[i-2] + 2;
					} else {
						if (i - dp[i-1] - 1 >= 0 && s[i - dp[i-1] - 1] == '('){
							if (i-dp[i-1]-2 >= 0)
								dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-1-1];
							else
								dp[i] = dp[i-1] + 2;
						}
					}
					curMax = max(dp[i],curMax);
				}
			}
			return curMax;
		}
};
#else
class Solution {
	public:
		int longestValidParentheses(string s){
			vector<int> dp(s.size() + 1, 0);
			int curMax = 0;
			for (int i = 0 ; i < s.size() ; i++){
				if (s[i] == '(')
					continue;
				else {
					if (i==0)
						continue;
					if (s[i-1] == '('){
						dp[i+1] = dp[i-1] + 2;
					} else {
						if (i - dp[i] - 1)
					}
					curMax = max(dp[i],curMax);
				}
			}
			return curMax;
		}
};
#endif

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	vector<int> ret_vec;
	int ret;
//	ret = sol.longestValidParentheses(")()())");
//	ret = sol.longestValidParentheses(")((()))");
	ret = sol.longestValidParentheses("()((()))");
	cout << ret << endl;

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

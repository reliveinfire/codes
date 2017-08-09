#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <unordered_set>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	unordered_set<string> dict;
	vector<string> wordBreak(string s, vector<string>& wordDict){
		int i;
		for (i = 0 ; i < wordDict.size() ; i++){
			dict.insert(wordDict[i]);
		}
		vector<int> dp(s.size(), 0);
		for (i = s.size() - 1 ; i >= 0 ; i--){
			string tmp = s.substr(i, s.size() - i);
			if (dict.count(tmp)!=0){
				dp[i] = 1;
			} else {
				for (int j = i+1 ; j < s.size() ; j++){
					if (dp[j]){
						string sub = s.substr(i, j-i);
						if (dict.count(sub)!=0)
							dp[i] = 1;
					}
				}
			}
		}
		vector<string> ans;
		vector<string> st;
		helper(s, 0, st, ans, dp);
		return ans;
	}
	void helper(string& s, int start, vector<string>& st, vector<string>& ans, vector<int>& dp)
	{
		for (int i = start + 1; i < s.size() ; i++ ){
			if (dp[i]){
				string tmp = s.substr(start,i-start);
				if (dict.count(tmp)!=0){
					st.push_back(tmp);
					helper(s,i, st, ans,dp);
					st.pop_back();
				}
			}
		}
		string ss=  s.substr(start, s.size()-start);
		if (dict.count(ss)!=0){
			string last;
			for (int i = 0 ; i < st.size() ; i++)
				last = last + st[i] + string(" ");
			last += ss;
			ans.push_back(last);
		}
		return;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	Solution sol;
	vector<string> dic;
	dic.push_back("cat");
	dic.push_back("cats");
	dic.push_back("and");
	dic.push_back("sand");
	dic.push_back("dog");
	vector<string> ret_vec;
	int ret;
	ret_vec = sol.wordBreak("catsanddog", dic);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << endl;
	cout <<endl;

	return 0;
}

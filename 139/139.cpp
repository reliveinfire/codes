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
		bool wordBreak(string s, vector<string>& wordDict){
			map<string,int>	dict;
			for (int i = 0 ; i < wordDict.size() ; i++){
				dict[wordDict[i]] = 1;
			}
			vector<bool> dp(s.size()+1, false);
			dp[0] = true;

			for (int i = 1 ; i <= s.size() ; i++ ){
				for (int j = i-1 ; j >=0 ; j--){
					if (dp[j]){
						// 注意此處substre取的範圍!
						string tmp = s.substr(j, i-j);
						if (dict.find(tmp) != dict.end()){
							dp[i] = true;
							break;
						}
					}
				}
			}
			return dp[s.size()];
		}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	vector<string> dict;
	Solution sol;
	bool ret;
#if 0
	dict.push_back("leet");
	dict.push_back("code");
	ret = sol.wordBreak("leetcode", dict);
#else
	dict.push_back("aaa");
	dict.push_back("aaaa");
	ret = sol.wordBreak("aaaaaaa", dict);
#endif
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

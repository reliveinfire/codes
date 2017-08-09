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
bool lencompare(const string& a, const string& b)
{
	return a.size() < b.size();
}
class Solution {
	public:
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words){
		map<string, int> table;
		vector<string> result;
		if (words.size() < 2)
			return result;
		for (int i = 0 ; i < words.size() ; i++){
			table[words[i]] = 1;
		}
		for (int i = 0 ; i < words.size() ; i++){
			if (canGen(words[i], table))
				result.push_back(words[i]);
		}
		
		return result;
	}
	bool canGen(string s, map<string, int>& table){
		vector<bool> dp(s.size()+1, false);
		dp[0] = true;
		for (int i = 1 ; i <= s.size() ; i++){
			for (int j = i-1 ; j>=0 ; j--){
				string tmp = s.substr(j, i-j);
				if (tmp.size() == s.size())
					continue;
				if (dp[j]){
					if (table.find(tmp)!=table.end()){
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
	vector<string> ret_vec;
	vector<string> words;
	words.push_back("cat");
	words.push_back("cats");
	words.push_back("catsdogcats");
	words.push_back("dog");
	words.push_back("dogcatsdog");
	words.push_back("rat");
	words.push_back("ratcatdogcat");
	Solution sol;
	ret_vec = sol.findAllConcatenatedWordsInADict(words);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

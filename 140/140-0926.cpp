#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        vector<string> wordBreak(string s, vector<string>& wordDict){
		unordered_set<string> dic;
		unordered_map<string, vector<string>> dp;
		for (string ss : wordDict)
			dic.insert(ss);
		return helper(s, dp, dic);
        }
	vector<string> helper(string s, unordered_map<string, vector<string>>& dp, unordered_set<string>& dic){
			if (s.empty())
				return {};
			if (dp.count(s)!=0)
				return dp[s];
			vector<string> res;
			for (int i = 0 ; i < s.size()-1 ; i++){
				string pre = s.substr(0, i+1);
				if (dic.count(pre)!=0){
					string next = s.substr(i+1);
					vector<string> tmp = helper(next, dp, dic);
					for (int j = 0 ; j < tmp.size() ; j++){
						string it = pre + " " + tmp[j];
						res.push_back(it);
					}
				}
			}
			if (dic.count(s)!=0)
				res.push_back(s);
			dp[s] = res;
			return res;
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
        ret_vec = sol.wordBreak("catsanddog", dic);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

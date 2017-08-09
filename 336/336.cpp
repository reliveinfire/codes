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
struct pair_hash
{
	size_t operator()(const std::pair<int,int>& p) const{
		return p.first * 31  + p.second;
	}
};
class Solution {
	public:
	vector<vector<int>> palindromePairs(vector<string>& words){
		unordered_map<string,int> table;
		vector<vector<int>> ans;
		unordered_set<pair<int,int>, pair_hash> ret;
		for (int i = 0 ; i < words.size() ; i++){
			string tmp = words[i];
			reverse(tmp.begin(), tmp.end());
			table[tmp] = i;
		}
		for (int i = 0 ; i < words.size() ; i++){
			string target = words[i];
//			cout << "curr:" << target << endl;
			for (int j = 0 ; j <= target.size() ; j++){
				string str1 = target.substr(0, j);
				string str2 = target.substr(j, target.size() - j);
//				cout << str1 <<":" << str2 << endl;
				
				if (isPalindrome(str1)){
					auto it = table.find(str2);
					if (it!=table.end()){
						if (it->second != i)
							ret.insert(pair<int,int>(it->second, i));
					}
				}
				if (isPalindrome(str2)){
					auto it = table.find(str1);
					if (it!=table.end()){
						if (it->second != i)
						ret.insert(pair<int,int>(i, it->second));
					}
				}
			}
		}
		for (auto it = ret.begin() ; it != ret.end() ; it++){
			vector<int> row;
			row.push_back(it->first);
			row.push_back(it->second);
			ans.push_back(row);
		}
		return ans;
	}
	bool isPalindrome(string& s){
		int lo = 0, hi = s.size()-1;
		while(lo < hi){
			if (s[lo] == s[hi]){
				lo++;
				hi--;
			} else 
				return false;
		}
		return true;
	}
};

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
	vector<vector<int>> ret_vec;
	vector<string> dic;
#if 1
	dic.push_back("abcd");
	dic.push_back("dcba");
	dic.push_back("lls");
	dic.push_back("s");
	dic.push_back("sssll");
#endif
//	dic.push_back("a");
//	dic.push_back("");
	ret_vec = sol.palindromePairs(dic);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i][0] << "," << ret_vec[i][1] << endl;
	cout <<endl;

	return 0;
}

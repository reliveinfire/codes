#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
using namespace std;
#include "../helpers.cpp"
vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};


class Solution {
	public:
 	 vector<string> genAbbr(string s){
		vector<int> abbr(s.size(), 0);
		vector<string> ans;
		helper(s, 0, abbr, ans);
		return ans;
	}

	void helper(string& s, int cur, vector<int>& abbr, vector<string>& ans){
		if (cur == s.size()){
			string tmp;
			int count = 0;
			for (int i = 0 ; i < abbr.size() ; i++){
				if(abbr[i]){
					count++;
				} else {
					if (count!=0){
						tmp+= to_string(count);
						count = 0;
					}
					tmp += s[i];
				}
				if (i==abbr.size() - 1 && count != 0)
					tmp += to_string(count);
			}
			ans.push_back(tmp);
			return;
		}
		helper(s, cur + 1, abbr, ans);
		abbr[cur] = 1;
		helper(s, cur + 1, abbr, ans);
		abbr[cur] = 0;
		return;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	string tre("1,#,3,2,#,#,4,#,5,#,#");
	Codec cc;
	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
	Solution sol;
	auto ret_vec = sol.genAbbr("word");

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

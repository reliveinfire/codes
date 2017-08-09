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
        vector<string> letterCombinations(string digits){
                unordered_map<char, string> map;
                map['2'] = string("abc");
                map['3'] = string("def");
                map['4'] = string("ghi");
                map['5'] = string("jkl");
                map['6'] = string("mno");
                map['7'] = string("pqrs");
                map['8'] = string("tuv");
                map['9'] = string("wxyz");
                vector<string> ans;
                helper(digits, 0, string(""), ans, map);
                return ans;
        }
        void helper(string dig, int curr, string tmp, vector<string>& ans, unordered_map<char, string>& map)
	{
		if (curr == dig.size()){
			ans.push_back(tmp);
			return;
		}
		auto it = map.find(dig[curr]);
		if (it!=map.end()){
			string ss = it->second;
			for (int k = 0 ; k < ss.size() ; k++){
				helper(dig, curr+1, tmp + ss[k], ans, map);
			}
		} else {
			helper(dig, curr+1, tmp, ans, map);
		}
			return;
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
	vector<string> ret_vec;
	ret_vec = sol.letterCombinations("23");

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

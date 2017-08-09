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
	vector<vector<string>> groupStrings(vector<string>& strings){
		vector<vector<string>> ans;
		unordered_map<string, vector<string>> table;
		sort(strings.begin(), strings.end());
		for (string ss : strings){
			string num;
			for(int i = 1 ; i < ss.size() ; i++){
				int diff = ss[i] - ss[i-1];
				if (diff < 0)
					diff += 26;
				num += to_string(diff);
			}
			table[num].push_back(ss);
		}
		for (auto it=table.begin() ; it!=table.end() ; it++){
			ans.push_back(it->second);
		}
		return ans;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<string> ss = {"zab", "bcd", "abc", "acef", "xyz", "az", "ba", "a", "z"};
	Solution sol;
	vector<vector<string>> ret_vec;
	int ret;
	ret_vec = sol.groupStrings(ss);
	for (vector<string> item : ret_vec){
		for(string a : item){
			cout << a << " ";
		}
		cout << endl;
	}
	cout <<endl;

	return 0;
}

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
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	vector<string> genPaliPerm(string s){
		unordered_map<char,int> count;
		vector<string> ans;
		for (char c : s){
			count[c]++;
		}
		int oddCount = 0;
		char oddChar = -1;
		for (auto it = count.begin() ; it!=count.end() ; it++){
			cout << it->first <<":" << it->second << endl;
			if (it->second % 2 != 0){
				oddCount++;
				oddChar = it->first;
			//	count.erase(it);
			}
				cout << oddCount << endl;
			if (oddCount > 1)
				return {""};
		}
		gen("", s.size() / 2, ans, count);
		for (int i = 0 ; i < ans.size() ; i++){
			string tmp = ans[i];
			reverse(tmp.begin(), tmp.end());
			if (oddChar > 0)
				ans[i] = ans[i] + oddChar + tmp;
			else
				ans[i] = ans[i] + tmp;
		}
		return ans;
	}
	void gen(string ss, int size, vector<string>& ans, unordered_map<char,int>& count){
		if (ss.size() == size){
			ans.push_back(ss);
			return;
		}
		unordered_set<char> used;
		for (auto it = count.begin() ; it!=count.end() ; it++){
			if (used.count(it->first)==0 && it->second >= 2 ){
				used.insert(it->first);
				string tmp = ss + it->first;
				it->second -= 2;
				gen(tmp, size, ans, count);
				it->second += 2;
			}
		}
		return;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	Solution sol;
	vector<string> ret_vec;
	int ret;
	ret_vec = sol.genPaliPerm("aabbbbb");

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

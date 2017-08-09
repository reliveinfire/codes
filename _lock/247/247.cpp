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
	unordered_map<char,char> map;
	vector<string> findStrobogrammatic(int n){
		map['0'] = '0';
		map['1'] = '1';
		map['6'] = '9';
		map['8'] = '8';
		map['9'] = '6';
		vector<string> ret = helper(n,n);
		vector<string> ans;
		for (int i = 0 ; i < ret.size() ; i++){
			if (ret[i][0] != '0')
				ans.push_back(ret[i]);
		}
		return ret;
	}
	vector<string> helper(int n, int m){
		vector<string> tmp;
		if (n == 0) {
			tmp.push_back(string(""));
			return tmp;
		} else if (n==1){
			tmp.push_back(string("0"));
			tmp.push_back(string("1"));
			tmp.push_back(string("8"));
			return tmp;
		} else {
			vector<string> ret;
			ret = helper(n-2, m);
			for (int i = 0 ; i < ret.size() ; i++){
				for (auto it = map.begin() ; it!=map.end() ; it++){
					if (n!=m || (n==m && it->first!='0')){
						string ss = it->first + ret[i] + it->second;
						tmp.push_back(ss);
					}
				}
			}
			return tmp;
		}
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
	ret_vec = sol.findStrobogrammatic(4);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";

	return 0;
}

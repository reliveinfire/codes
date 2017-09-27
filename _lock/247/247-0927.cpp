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
		if (n<=0)
			return {""};
		if (n==1){
			return {"0","1","8"};
		}
		vector<string> res;
		vector<string> tmp;
		tmp = helper(n-2,m);
		for (string s : tmp){
			res.push_back("1" + s + "1");
			res.push_back("6" + s + "9");
			res.push_back("9" + s + "6");
			res.push_back("8" + s + "8");
			if (n!=m)
				res.push_back("0" + s + "0");
		}
		return res;
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

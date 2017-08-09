#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	 string minWindow(string s, string t){
	 	int dic[256] = {0};
		int min = INT_MAX, retL, retR;
	 	if (s.empty())
			return string("");
		if (t.empty())
			return s;
		for (int i = 0 ; i < t.size() ; i++)
			dic[t[i]]++;
		int j = 0;
		for (int i = 0 ; i < s.size() ; i++){
			dic[s[i]]--;
			while(isMatch(dic)){
				if (i - j + 1 < min){
					min = i - j + 1;
					retL = j;retR = i;
				}
				dic[s[j]]++;
				j++;
			}
		}
		if (min == INT_MAX)
			return string("");
		else
			return s.substr(retL, retR - retL + 1);
	}
	bool isMatch(int dic[])
	{
		for (int i = 0 ; i < 256 ; i++){
			if (dic[i] > 0)
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
	vector<int> ret_vec;
	int ret;
	ret = sol.
	ret_vec = sol.
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

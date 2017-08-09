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
	string nearestPalindromic(string n){
		string ans;
		long val = stol(n);
		long add = val+1;
		long minus = val-1;
		string addstr = to_string(add);
		string minusstr = to_string(add);
		string first = n.substr(0, n.size() / 2);
		string second = first;
		reverse(second.begin(), second.end());
		if (n.size()%2 ==0){
			ans = first + second;
		} else {
			ans = first + n[n.size() / 2] + second;
		}
		if (ans != n)
			return ans;
		if (n.size()%2 == 0){
			minus(first);
			if (first[0]!='0'){
				string tmp =first;
				reverse(tmp.begin(), tmp.end());
				return first + tmp;
			}

		} else{
			first += n[n.size() / 2];
			minus(first);
			if (first[0]!='0'){
				string tmp = first.substr(0, first.size() - 1);
				reverse(tmp.begin(), tmp.end());
				return first + tmp;
			}
		}
		ans.clear();
		for (int i = 0 ; i < n.size() - 1 ; i++)
			ans+= '9';
		return ans;
	}
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
	cout << sol.nearestPalindromic("100");

	cout <<endl;

	return 0;
}

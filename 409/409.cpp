#include <iostream>
#include <string>
#include <unordered_map>
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
	int longestPalindrome(string s){
		unordered_map<char, int> numcount;
		for (int i = 0 ; i < s.size() ; i++){
			numcount[s[i]]++;
		}
		int odd = 0;
		int ans = 0;
		for (unordered_map<char,int>::iterator iter = numcount.begin();
			iter!=numcount.end() ; iter++){
				if (iter->second % 2 == 1)
					odd = 1;
				int tmp = iter->second/ 2 * 2;
				ans += tmp;
			}
			ans+= odd;
		return ans;
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
	ret = sol.longestPalindrome("abccccdd");
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

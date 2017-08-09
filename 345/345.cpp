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
	string reverseVowels(string s) {
		int lo = 0, hi = s.size() - 1;
		while(true){
			while(lo < s.size() && tolower(s[lo])!= 'a' && 
				               tolower(s[lo])!= 'e' &&
					      tolower(s[lo])!= 'i' &&
					      tolower(s[lo])!= 'o' &&
					      tolower(s[lo])!= 'u') lo++;
			while(hi >= 0 &&tolower(s[hi])!= 'a' &&
			                tolower(s[hi])!= 'e' &&
					tolower(s[hi])!= 'i' &&
					tolower(s[hi])!= 'o' &&
					tolower(s[hi])!= 'u') hi--;
			if (lo>=hi)
				break;
			swap(s[lo], s[hi]);
			lo++;
			hi--;
		}
		return s;
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

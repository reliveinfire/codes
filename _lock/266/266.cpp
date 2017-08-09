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
	bool isPalindromePerm(string s){
		// 用hashset也可以.
		unordered_map<char,int> count;
		int isEven = 0;
		if (s.size()%2 == 0){
			isEven = 1;
		}
		for (int i = 0 ; i < s.size() ; i++){
			count[s[i]]++;
			if (count[s[i]] == 2){
				count.erase(s[i]);
			}
		}
		//條件, isEven 不需要 (?)
		if (count.size()==1 && !isEven)
			return true;
		else if (count.size()==0 && isEven)
			return true;
		else
			return false;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret = sol.isPalindromePerm("code");
	cout << ret << "\n";
	ret = sol.isPalindromePerm("aab");
	cout << ret << "\n";
	ret = sol.isPalindromePerm("carcare");
	cout << ret << "\n";
	ret = sol.isPalindromePerm("carcar");
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

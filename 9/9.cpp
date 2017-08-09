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
	bool isPalindrome(int x){
		if (x<0)
			return false;
		if (x>=0 && x < 10)
			return true;
		int digit = 0;
		int tmp = x;
		while(tmp!=0){
			tmp = tmp/10;
			digit++;
		}
		int ll,rr;
		if (digit % 2 == 0){
			ll = digit/2 + 1;
			rr = digit/2;
		} else
			ll = rr = digit/2 + 1;
		while(rr > 0){
			int rnum = x, lnum=x;
			for (int i = 0 ; i < rr - 1 ; i++)
				rnum = rnum/10;
			rnum = rnum % 10;
			for (int i = 0 ; i < ll - 1 ; i++)
				lnum = lnum/10;
			lnum = lnum % 10;
			if (rnum == lnum){
				ll++;rr--;
			} else
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

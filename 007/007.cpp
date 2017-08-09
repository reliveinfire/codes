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
	int reverse(int x){
		bool positive = 1;
		if (x < 0){
			x = -x;
			positive = 0;
		}
		string tmp = to_string(x);
		int lo = 0, hi = tmp.size() - 1;
		while (lo < hi){
			char cc = tmp[lo];
			tmp[lo] = tmp[hi];
			tmp[hi] = cc;
			lo++;
			hi--;
		}
		long result = 0;
		for (int i = 0 ; i < tmp.size() ; i++){
			result = result*10 + tmp[i] - '0';
		}
		if (positive){
			if (result > INT_MAX)
				return 0;
		} else {
			result = -result;
			if (result < INT_MIN)
				return 0;
		}
		return (int)result;
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

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
	int mySqrt(int x){
		if (x== 0)
			return x;
		long lo = 1, hi = x;
		while(lo <= hi){
			long mid = (lo + hi) / 2;
			if ((long)mid*mid == (long)x)
				return mid;
			else if ((long)mid*mid > (long)x)
				hi = mid - 1;
			else
				lo = mid + 1;
		}
		return lo - 1;
	}
};

class Solution2 {
	public:
	int mySqrt(int x){
		if (x== 0)
			return x;
		long lo = 1, hi = x;
		while(lo < hi){
			long mid = lo + (hi-lo) / 2;
			if (mid*mid > (long)x)
				hi = mid;
			else
				lo = mid + 1;
		}
		return lo - 1;
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
	Solution2 sol2;
	vector<int> ret_vec;
	int ret;
	cout << sol.mySqrt(9) << "\n";
	cout << sol2.mySqrt(9) << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

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
#include <deque>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	vector<int> plusOne(vector<int>& digits){
		vector<int> ans;
		if (digits.empty())
			return ans; 
		int n = digits.size();
		ans.resize(n);
		int tmp, carry = 0;
		for (int i = n - 1 ; i >= 0 ; i--){
			if (i == n - 1)
				tmp = digits[i] + 1 + carry;
			else
				tmp = digits[i] + carry;
			carry = tmp / 10;
			ans[i] = tmp % 10;
		}
		if (carry)
			ans.insert(ans.begin(), carry);
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
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

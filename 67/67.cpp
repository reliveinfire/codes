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
	string addBinary(string a, string b) {
		int aidx = a.size()-1;
		int bidx = b.size()-1;
		strin ans;
		int tmp, carry = 0;
		while(aidx>=0 && bidx>=0){
			tmp = a[aidx] - '0' + b[bidx] - '0' + carry;
			ans += to_string(tmp%2);
			carry = tmp/2;
			aidx--;
			bidx--;
		}
		while(aidx >= 0){
			tmp = a[aidx] - '0' + carry;
			ans += to_string(tmp%2);
			carry = tmp/2;
			aidx--;
		}
		while(bidx >= 0){
			tmp = b[bidx] - '0' + carry;
			ans += to_string(tmp%2);
			carry = tmp/2;
			bidx--;
		}
		if (carry)
			ans += to_string(1);
		reverse(ans.begin(), ans.end());
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
	ret = sol.
	ret_vec = sol.
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

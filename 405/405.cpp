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
	string toHex(int ii){
		if (ii == 0)
			return string("0");
		string ans;
		unsigned int num;
		if (num < 0){
			num = UINT_MAX + (num + 1);
		} else {
			num = ii;
		}
		while(num > 0){
			int mod = num % 16;
			num = num / 16;
			string digit;
			if (mod >=10){
				char c = 'a' + (mod - 10);
				digit += c;
			} else {
				digit += to_string(mod);
			}
			ans += digit;
		}
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
	string ret;
	ret = sol.toHex(INT_MAX);
	cout << ret << endl;

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

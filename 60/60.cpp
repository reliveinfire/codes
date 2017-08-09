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
	string getPermutation(int n, int k){
		string ans;
		int perm = 1;
		vector<int> nums;
		for(int i = 1 ; i <= n ; i++)
			nums.push_back(i);

		for (int i = 1 ; i <= n ; i++)
			perm = perm*i;
		if (k > perm)
			return string("");
		perm = perm/n;
		k = k -1;
		for (int i = n-1 ; i >=0 ; i--){
			int seq = k / perm;
			k = (k % perm);
			if (i!=0)
				perm = perm / i;
			ans += to_string(nums[seq]);
			nums.erase(nums.begin() + seq);
		}
			
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
	ret = sol.getPermutation(4,3);
	cout << ret << endl;

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

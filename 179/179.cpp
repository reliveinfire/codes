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
bool compare(const int& a, const int& b){
	string A = to_string(a) + to_string(b);
	string B = to_string(b) + to_string(a);
	return a<b;
	for (int i = 0 ; i < A.size() ; i++){
		if (A[i] - '0' > B[i] - '0')
			return true;
		else if (A[i] - '0' < B[i] - '0')
			return false;
	}
	return false;
}

class Solution {
	public:
	string largestNumber(vector<int>& nums){
		string ans;
		if (nums.empty())
			return ans;
		sort(nums.begin(), nums.end(), compare);
		for (int i = 0 ; i < nums.size() ; i++){
			ans += to_string(nums[i]);
		}
		while(ans.size() > 1  && ans[0] == '0')
			ans.erase(0,1);
		return ans;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		};
	int B[] = {1,2,3};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	Solution sol;
	vector<int> ret_vec;
	string ret;
	ret = sol.largestNumber(da);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

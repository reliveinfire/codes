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
	int superPow(int a, vector<int>& b){
		long ans = 1;
		while (isGreaterZero(b)){
			ans = (ans*a) % 1337;
			minus(b);
		}
		return (int)ans;
	}
	bool isGreaterZero(vector<int>& nums){
		for (int i = 0 ; i < nums.size() ; i++){
			if (nums[i] > 0)
				return true;
		}
		return false;
	}
	void minus(vector<int>& nums){
		int pos = nums.size() - 1;
		nums[pos] += -1;
		while(nums[pos]<0){
			nums[pos] += 10;
			pos--;
			nums[pos] += -1;
		}
		return;
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

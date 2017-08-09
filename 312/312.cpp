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
#include "../helpers.cpp"
vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};


class Solution {
	public:
	unordered_map<string, int> tb;
	int maxCoins(vector<int>& nums) {
		return helper(nums);
	}
	int helper(vector<int> nums){
		int ans = INT_MIN;
		string tmp = vec2str(nums);
		if (tb.count(tmp)!=0)
			return tb.find(tmp)->second;
		for (int i = 0 ; i < nums.size() ; i++){
			vector<int> cu = nums;
			int tv = 0;
			if (nums.size() == 1)
				tv = nums[0];
			else if (i == 0)
				tv = nums[i] * nums[i+1];
			else if (i == nums.size() - 1) 
				tv = nums[i-1] * nums[i];
			else
				tv = nums[i-1] * nums[i] * nums[i+1];

			cu.erase(cu.begin() + i);
			if (cu.size() != 0)
				tv += helper(cu);
			if (tv > ans)
				ans = tv;
		}
		tb[tmp] = ans;
		return ans;
	}

	string vec2str(vector<int>& vec){
		string str;
		for (int i = 0 ; i < vec.size() ; i++)
			str += to_string(vec[i]) + string(",");
		return str;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {8,2,6,8,9,8,1,4,1,5,3,0,7,7,0,4,2};
	vector<int> B = {1,2,3};
	string tre("1,#,3,2,#,#,4,#,5,#,#");
	Codec cc;
	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret = sol.maxCoins(A);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

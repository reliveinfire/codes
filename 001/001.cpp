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
	vector<int> twoSum(vector<int>& nums, int target){
		unordered_map<int,int> tb;
		vector<int> ans;
		for (int i = 0 ; i < nums.size() ; i++){
			int tmp = target - nums[i];
			if (tb.find(tmp)!= tmp.end()){
				int idx = tb[tmp];
				if (idx > i){
					ans.push_back(i);
					ans.push_back(idx);
				} else {
					ans.push_back(idx);
					ans.push_back(i);
				}
				break;
			}
			tb[nums[i]] = i;
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
	int ret;
	ret = sol.
	ret_vec = sol.
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

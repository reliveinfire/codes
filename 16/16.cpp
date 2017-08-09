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
	int threeSumClosest(vector<int>& nums, int target){
		int ans;
		int mindiff = INT_MAX;
		sort(nums.begin(), nums.end());
		for (int i = 0 ; i + 2 < nums.size() ; i++){
			int lo = i+1, hi = nums.size() - 1;
			while(lo < hi){
				int total = nums[i] + nums[lo] + nums[hi];
				if (abs(target-total) < mindiff){
					ans = total;
					mindiff = abs(target-total);
				}
				if (total == target){
					return ans;	
				} else if (total > target){
					hi--;
				} else
					lo++;
			}
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

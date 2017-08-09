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
	vector<vector<int>> fourSum(vector<int>& nums, int target){
		vector<vector<int>> ans;
		vector<int> row;
		sort(nums.begin(), nums.end());
		for (int i = 0 ; i + 3 < nums.size() ; i++){
			cout << "i:" << i << endl;
			if (i==0 || nums[i-1] != nums[i]){
				for(int j = i+1; j + 2 < nums.size() ; j++){
					cout << "j:" << j << endl;
					if (j==i+1 || nums[j-1]!=nums[j]){
						int lo = j+1, hi = nums.size() - 1;
						int sum = 0 - nums[i] - nums[j];
						while(lo<hi){
						cout << i<<":"<<j<<":"<<lo<<":"<<hi << endl;
							row.clear();
							if (nums[lo]+nums[hi]==sum){
								row.push_back(nums[i]);
								row.push_back(nums[j]);
								row.push_back(nums[lo]);
								row.push_back(nums[hi]);
								ans.push_back(row);
								lo++; hi--;
								while(lo < nums.size() && nums[lo]==nums[lo-1]) lo++;
								while(hi > j && nums[hi]==nums[hi+1]) hi--;
							} else if (nums[lo] + nums[hi] < sum)
								lo++;
							else 
								hi--;
						}
					}
				}
			}
		}
		return ans;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
//	int A[] = {1,0,-1,0,-2,2};
	int A[] = {0,0,0,0};
	genVector(da, A);
	vector<vector<int>> ret_vec;
	Solution sol;
	ret_vec = sol.fourSum(da, 1);

	for (int i = 0 ; i < ret_vec.size() ; i++){
		for (int j = 0 ; j < ret_vec[0].size() ; j++)
			cout << ret_vec[i][j] << " ";
		cout << endl;
	}

	return 0;
}

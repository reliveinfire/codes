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
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
		map<int,int> table;
		int i,j;
		if (t < 0)
			return false;
		j = 0;
		for (i = 0 ; i < nums.size(); i++){
			int idx = getIdx(nums[i], t);
			if ( i - j  > k){
				table.erase(getIdx(nums[j],t));
				j++;
			}
			if (table.find(idx) == table.end()){
				table[idx] = nums[i];
				if (t==0)
					continue;
				if (table.find(idx+1) != table.end()){
					if (abs(nums[i] - table[idx+1]) <= t)
						return true;
				}
				if (table.find(idx-1) != table.end()){
					if (abs(nums[i] - table[idx-1]) <= t)
						return true;
				}
			} else {
				return true;
			}
		}
		return false;
	}

	int getIdx(int x, int t){
		if (t == 0 || t==1)
			return x;
		if (x >= 0)
			return x / t;
		else
			return (x / t) - 1;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {-1,-1};
	genVector(da, A);
	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret = sol.containsNearbyAlmostDuplicate(da,1,-1);
	cout << ret << "\n";
	
	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

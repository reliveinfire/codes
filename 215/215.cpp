#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	int findKthLargest(vector<int>& nums, int k){
		return	quickSelect(nums, 0, nums.size() - 1, k-1);
	}

	int quickSelect(vector<int>& nums, int start, int end, int k){
		int pivot = nums[start];
		int ll = start + 1, rr = end, tmp;
		cout << start << ":" << end << endl;
		while (true){
			while(ll < end && nums[ll] >= pivot )
				ll++;
			while(rr > start && nums[rr] < pivot)
				rr--;
			if (ll>=rr)
				break;
			tmp = nums[ll];
			nums[ll] = nums[rr];
			nums[rr] = tmp;
		}
		tmp = nums[start];
		nums[start] = nums[rr];
		nums[rr] = tmp;
		if (rr == k){
			return nums[rr];
		} else if (rr > k){
			return quickSelect(nums, start, rr - 1, k);
		} else {
			return quickSelect(nums, rr+1, end, k);
		}
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {-1,2,0};
	int B[] = {3,3,3,3};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret = sol.findKthLargest(da,3);
	cout << ret << "\n";
	ret = sol.findKthLargest(db,1);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

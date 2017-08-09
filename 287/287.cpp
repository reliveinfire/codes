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
	int findDuplicate(vector<int>& nums){
		int n = nums.size()-1;
		int lo = 1, hi = n + 1;
		while(lo<hi){
			int mid = lo + (hi-lo) / 2;
			int count = 0;
			for (int i = 0 ; i < nums.size() ; i++){
				if (nums[i] <= mid)
					count++;
			}
			if (count > mid)
				hi = mid;
			else
				lo = mid+1;
		}
		return lo;	
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {1,2,6,4,5,6};
	int B[] = {1,2,3};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret = sol.findDuplicate(da);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

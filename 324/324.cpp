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
	void wiggleSort(vector<int>& nums){
		int mid = quickSelect(nums.size() / 2);
		#define A(i) nums[(i*2)%(nums.size()|1)]
		int i = 0, j = 0, k = nums.size() - 1;
		while(i<=k){
			if (nums[i] > mid){
				swap(nums[i], nums[k]);
				k--;
			} else if (nums== mid){
				i++;
			} else {
				swap(nums[i], nums[j]);
				i++;
				j++;
			}
		}
		return;
	}
	int vidx(int idx, int n){
		if (idx == 0)
			return 0;
		if (n%2 == 0){
			n = n-1;
			idx = (idx * 2) % n;
			if (idx == 0)
				return n;
			else
				return idx;
		} else 
			return (idx * 2) % n

	}
	int quickSelect(vector<int>& nums, int left, int right, int idx){
		int pivot= nums[left];
		int ll = left + 1, rr = right; 
		while(true){
			while(nums[ll] < pivot && ll < right ) ll++;
			while(nums[rr] > pivot && rr > left ) rr--;
			if (ll>=rr)
				break;
			swap(nums[ll], nums[rr]);
			ll++;
			rr--;
		}
		swap(nums[left], nums[rr])
		if (rr = idx)
			return nums[rr]
		else (rr > idx)
			return quickSelect(nums, left, rr-1, idx);
		else
			return quickSelect(nums, rr+1, right, idx);
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

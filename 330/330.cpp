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
	int minPatches(vector<int>& nums, int n){
		int ans = 0, idx = 0;
		long curr = 0, miss;
		while(curr < n){
			miss = curr+1;
			if (idx < nums.size()){
				if (nums[idx] > miss){
					ans++;
					curr +=miss;
				} else {
					curr += nums[idx];
					idx++;
				}
			} else {
				ans++;
				curr += miss;
			}
		}
		return ans;	
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {1,3};
	int B[] = {1,5,10};
	int C[] = {1,2,2};
	genVector(da, A);
	genVector(db, B);
	genVector(dc, C);
	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret = sol.minPatches(da, 6);
	cout << ret << "\n";
	ret = sol.minPatches(db, 20);
	cout << ret << "\n";
	ret = sol.minPatches(dc, 5);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

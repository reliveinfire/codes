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
#if 0
class Solution {
	public:
	int minSubArrayLen(int s, vector<int>& nums){
		int ll = 0, rr = 0;
		int sum = 0;
		int tmin = INT_MAX;
		for (;rr < nums.size() ; rr++){
			sum += nums[rr];
			while (sum >= s){
				int len = rr - ll + 1;
				tmin = min(len, tmin);
				sum -= nums[ll];
				ll++;
			}
		}
		if (tmin == INT_MAX)
			return 0;
		else
			return tmin;
	}
};
#else
class Solution {
	public:
	int minSubArrayLen(int s, vector<int>& nums){
		vector<int> sum(nums.size(), 0);
		int cs = 0;
		for (int i = 0 ; i < nums.size() ; i++){
			cs += nums[i];
			sum[i] = cs;
		}
		int ret = INT_MAX;
		for (int i = 0 ; i < nums.size() ; i++){
			int ll = i;
			int rr = nums.size() - 1;
			int tmp;
			while (ll<=rr){
				int mid = (ll + rr ) / 2;
				if (i==0){
					tmp = sum[mid];
				} else {
					tmp = sum[mid] - sum[i-1];
				}
				if (tmp >= s){
					ret = min(ret, mid - i + 1);
					rr = mid - 1;
				} else {
					ll = mid +1;
				}
			}
		}
		return ret;
	}
};
#endif
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {2,3,1,2,4,3};
	int B[] = {1,5,4};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	int ret;
	ret = sol.minSubArrayLen(7, da);
	cout << ret << "\n";
	ret = sol.minSubArrayLen(4, db);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

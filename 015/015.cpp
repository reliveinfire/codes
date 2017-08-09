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

class triple{
	int a;
	int b;
	int c;
	triple(int _a, int _b, int _c): a(_a),b(_b),c(_c){}
};
class Solution {
	public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		unordered_set<triple> triple;
		for (int i = 0 ; i < nums.size() ; i++)
			element.insert(nums[i]);
		triple tr;
		for (int i = 0 ; i < nums.size() ; i++){
			for (int j = 0 ; j < nums.size() ; j++){
				for (int k = 0 ; k < nums.size() ; k++){
					if (i!=j && i != k && j != k){
						if (nums[i] + nums[j] + nums[k] == 0){
							tr.a = nums[i];
							tr.b = nums[j];
							tr.c = nums[k];
						}
					}
				}
		}
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

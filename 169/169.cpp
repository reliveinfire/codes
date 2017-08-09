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
	int majorityElement(vector<int>& nums){
		int curr;
		int count = 0;
		for (int i = 0 ; i < nums.size() ; i++){
			if (i == 0){
				curr = nums[i];
				count++;
			} else {
				if (nums[i]==curr){
					count++;
				} else {
					count--;
					if (count<0){
						count=1;
						curr = nums[i];
					}
				}
			}
		}
		count = 0;
		for (int i = 0 ; i < nums.size() ; i++){
			if (nums[i] == curr)
				count++;
		}
		if (count>nums.size()/2)
			return curr;
		
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {2,2};
	int B[] = {1,2,3};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret = sol.majorityElement(da);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

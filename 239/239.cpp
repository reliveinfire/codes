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
#include <deque>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k){
		deque<int> dq;
		vector<int> ans;
		int j = 0;
		for (int i = 0 ; i < nums.size() ; i++){
			while(!dq.empty() && dq.back() < nums[i])
				dq.pop_back();
			dq.push_back(nums[i]);

			if (i-j+1 == k){
				ans.push_back(dq.front());
				if (nums[j] == dq.front())
					dq.pop_front();
				j++;
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

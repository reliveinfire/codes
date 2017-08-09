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
	bool increasingTriplet(vector<int>& nums){
		vector<int> st;
		for (int i = 0 ; i < nums.size() ; i++){
			if (st.empty()){
				st.push_back(nums[i]);
			} else {
				for (int j = 0 ; j < st.size() ; j++){
					if (nums[i] <= st[j]){
						st[j] =nums[i];
						break;
					}
				}
				if (i == st.size())
					st.push_back(nums[i]);
				if (st.size() == 3)
					return true;
			}
		}
		return false;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {2,1,5,0,3,4};
	int B[] = {1,2,3};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret = sol.increasingTriplet(da);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

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
	vector<vector<int>> ans;
	vector<vector<int>> subsets(vector<int>& nums){
		vector<int> st;
		vector<bool> pick(nums.size(), false);
		bt(nums, 0, st, pick);
		return ans;
	}

	void bt(vector<int>& nums, int start, vector<int>& st, vector<bool>& pick){
#if 1
			ans.push_back(st);
			if (start == nums.size()){
				for (int i = 0 ; i < pick.size() ; i++)
					cout << pick[i] << " ";
				cout << endl;
				return;
			}
#endif

			for (int i = start ; i < nums.size() ; i++){
				st.push_back(nums[i]);
				pick[i] = true;
				bt(nums, i+1, st,pick);
				pick[i] = false;
				st.pop_back();
			}
			return;	
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
	vector<vector<int>> ret;
	ret = sol.subsets(da);
	cout << "print, ret size:" << ret.size()<<endl;
	for (int i = 0 ; i < ret.size() ; i++){
		for(int j = 0 ; j < ret[i].size() ; j++)
			cout << ret[i][j] << " ";
		cout << endl;
	}

	return 0;
}

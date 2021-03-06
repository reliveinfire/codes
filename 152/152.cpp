#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
TreeNode* genBST(vector<int>& pre)
{
        int idx = 0;
        TreeNode* node = new TreeNode(pre[idx++]);
        stack<TreeNode*> st;
        st.push(node);
        while(idx < pre.size()){
                if (pre[idx] < st.top()->val){
                        st.top()->left = new TreeNode(pre[idx++]);
                        st.push(st.top()->left);
                } else {
                        TreeNode* tmp;
                        while(!st.empty() && st.top()->val < pre[idx]){
                                tmp = st.top();
                                st.pop();
                        }
                        tmp->right = new TreeNode(pre[idx++]);
                        st.push(tmp->right);
                }
        }
        return node;
}


class Solution {
	public:
	int maxProduct(vector<int>& nums) {
		int curMax, curMin;
		int ans = INT_MIN;
		for (int i = 0 ; i < nums.size() ; i++){
			if (i==0 || nums[i-1] == 0){
				curMax = nums[i];
				curMin = nums[i];
				ans = max(curMax, ans);
			} else {
				int tMax = max(nums[i],max(nums[i]* curMax, nums[i]*curMin));
				int tMin = min(nums[i],min(nums[i]* curMax, nums[i]*curMin));
				ans = max(tMax, ans);
				curMax = tMax;
				curMin = tMin;
			}
		}
		return ans;	
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {-4,3,2};
	vector<int> B = {1,2,3};
	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret = sol.maxProduct(A);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

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
	bool canWinNim(int n){
		vector<int> mem(n+1, -1);
		return helper(n,0,mem);
	}

	bool helper(int n, int player, vector<int>& mem){
		if (player == 0){
			if (n<=3)
				return true;
			int ret;
			for (int i = 1 ; i <= 3 ; i++){
				ret = !helper(n-i, 0, mem);
				if (ret)
					return true;
			}
			return false;
		} else {
			if (n<=3)
				return false;
			int ret;
			for (int i = 1 ; i <= 3 ; i++){
				ret = helper(n-i, 0, mem);
				if (!ret)
					return false;
			}
			return true;
		}
	}

};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	Solution sol;
	vector<int> ret_vec;
	int ret;
	for (int i = 4 ; i <= 32 ; i++){
		cout << i <<":" << sol.canWinNim(i) <<endl;
	}
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

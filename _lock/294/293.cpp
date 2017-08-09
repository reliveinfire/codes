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
	unordered_set<string> mem;
	vector<string> genMoves(string s){
		vector<string> ans;
		for (int i = 0 ; i+1 < s.size() ; i++){
			if (s[i]== s[i+1]  && s[i] == '+'){
				string ss = s;
				ss[i] = ss[i+1] = '-';
				ans.push_back(ss);
			}
		}
		return ans;
	}
	bool canWin(string s){
		return helper(s, 0);	
	}

	bool helper(string s, int player){
//	cout <<"P:"<< player <<":"<< s << endl;
		if (player == 0){
			vector<string> moves = genMoves(s);
			if (moves.empty())
				return false;
			for (int i = 0 ; i < moves.size() ; i++){
				string move = moves[i];
				int ret = helper(move, 1);
					if (ret)
						return true;
			}
			return false;
		} else {
			vector<string> moves = genMoves(s);
			if (moves.empty())
				return true;
			for (int i = 0 ; i < moves.size() ; i++){
				string move = moves[i];
				int ret = helper(move, 0);
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
	vector<string> ret_vec;
	int ret;
	cout << sol.canWin("++++") << endl;

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

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

void pre(TreeNode* node){
	stack<TreeNode*> st;
	st.push(node);

	while(!st.empty()){
		if (st.top() != NULL){
			cout << st.top();
			st.push(st.top()->left);
		} else {
			st.pop();
			TreeNode* tmp = st.top()->right;
			st.pop();
			st.push(tmp);
		}
	}
}
struct State{
	string type;
	int left;
	int right;
}
class Solution {
	public:
	bool isValidSerialization(string preorder){
		queue<string> qu;
		Stack<State> st;
		st.push({qu.front(),0,0});
		qu.pop();
		while(!qu.empty()){
			if (st.top().type != string("#")){
				st.top().left = 1;
				st.push({qu.front(), 0 , 0});
				qu.pop();
			} else {
				st.pop();
				while(!st.empty() && st.top().right){
					st.pop();
				}
				if (st.empty())
					return false;
				else
				    
			}
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
	ret = sol.
	ret_vec = sol.
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

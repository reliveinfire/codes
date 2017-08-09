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
	string decodeString(string s){
		stack<string> st;
		int num = 0;
		for (int i = 0 ; i < s.size() ; i++){
			if (s[i] == '['){
				st.push(to_string(num));
				st.push("[");
				num = 0;
			} else if (s[i] >= '0' && s[i]<='9'){
				num = num* 10 + s[i] - '0';
			} else if (s[i] == ']'){
				string ret;
				string word = st.top();
				st.pop();
				st.pop();
				string count = st.top();
				st.pop();
				for (int j = 0 ; j < stoi(count) ; j++)
					ret += word;
				if (st.empty())
					st.push(ret);
				else
					st.top() = st.top() + ret;
			} else {
				string ss;
				ss += s[i];
				if (st.top()!= string("[")){
					st.top() = st.top() + ss;
				} else
					st.push(ss);
			}
		}
		return st.top();	
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	Solution sol;
	vector<int> ret_vec;
	string ret;
	ret = sol.decodeString("3[a]2[bc]");
	cout << ret << "\n";
	
	ret = sol.decodeString("3[a2[c]]");
	cout << ret << "\n";
	
	ret = sol.decodeString("2[abc]3[cd]ef");
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

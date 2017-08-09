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
	vector<string> addOperators(string num, int target){
		int size = num.size();
		vector<string> ans;
		vector<string> op = {"+","-","*",""};
		helper(num, size - 1, target, op, ans);
		return ans;
	}
	void helper(string num, int pos, int target, vector<string>& op, vector<string>& ans){
		if (pos == 0){
			long long val;
			//cout << num << endl;
			int ret = eval(num, val);
			if (ret == 0 && val == target){
				ans.push_back(num);
			}
			return;
		}
		for (int i = 0 ; i < op.size() ; i++){
			string tmp = num;
			tmp.insert(pos, op[i]);
			helper(tmp, pos - 1, target, op, ans);
		}
		return;
	}
	int eval(string s, long long& val){
		vector<string> back;
		string tmp;
		stack<char> st;
		for (int i = 0 ; i < s.size() ; i++){
			if (s[i] >= '0' && s[i] <= '9')
				tmp+=s[i];
			else {
				back.push_back(tmp);
				if (tmp[0] == '0' && tmp.size() > 1)
					return -1;
				tmp.clear();
				while(!st.empty() && !hiop(st.top(), s[i])){
					string ss;
					ss+= st.top();
					back.push_back(ss);
					st.pop();
				}
				st.push(s[i]);
			}
			if (i == s.size() - 1){
				if (tmp[0] == '0' && tmp.size() > 1)
					return -1;
				back.push_back(tmp);
			}
		}
		while(!st.empty()){
			string ss; ss+=st.top(); st.pop();
			back.push_back(ss);
		}

		stack<string> ret;
		for (int i = 0 ; i < back.size() ; i++){
			//cout << i <<":"<<back[i] << endl;
			if (back[i] != string("+") && back[i]!=string("-") && back[i]!=string("*")){
				ret.push(back[i]);
			} else {
				string sec = ret.top(); ret.pop();
				string pre = ret.top(); ret.pop();
				//cout << pre <<":" << sec << endl;
				long long val;
				if (back[i] == string("+"))
					val = stoi(pre) + stoi(sec);
				else if (back[i] == string("-"))
					val = stoi(pre) - stoi(sec);
				else
					val = stoi(pre) * stoi(sec);
				ret.push(to_string(val));
			}
		}
		val = stoll(ret.top());
		return 0;
	}
	bool hiop(char a, char b){
		if (a==b){
			return false;
		} else {
			if (b=='*')
				return true;
			else
				return false;
		}
	}
	int eval2(string s){
		int ans = 0;
		int num = 0;
		int last;
		char op = '+';
		if (s[0] == '-')
			op = '-';
		for (int i = 0 ; i < s.size() ; i++){
			if (s[i] >= '0' && s[i] <= '9'){
				num = num*10 + s[i] - '0';
			} 
			if (i == s.size() - 1 || s[i]=='+' || s[i]=='-' ||
					s[i]=='*') {
				if (op == '+'){
					ans = ans + num;
					last = num;
				} else if (op == '-'){
					ans = ans - num;
					last = -num;
				} else
					ans = (ans - last) + num * last;
				num = 0;
				op = s[i];
			}
		}
		return ans;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	Solution sol;
	long long ret;
	//sol.eval("1*05", ret);
	cout << sol.eval2("1-2*3+4") << endl;
//	cout << ret << endl;
	vector<string> ret_vec;
//	ret_vec = sol.addOperators("123",6);
//	ret_vec = sol.addOperators("232",6);
//	ret_vec = sol.addOperators("105",5);
//	ret_vec = sol.addOperators("3456237490",9191);
	cout << "ans:\n";
	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

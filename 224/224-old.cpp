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
	int calculate(string s){
		stack<string> st;
		string ss;
		vector<string> post;
		int num = 0;
		for(int i = 0 ; i < s.size() ; i++){
			if (s[i] >= '0' && s[i] <= '9'){
				num = num*10 + s[i] - '0';
			} else if(s[i] == '+' || s[i] == '-' || s[i]=='*' || s[i]=='/'){
				post.push_back(to_string(num));
				num = 0;
				if(st.empty()){
					ss.clear();
					ss += s[i];
					st.push(ss);
				} else {
					ss.clear();
					ss += s[i];
					while(!st.empty() && greaterProi(st.top(), ss)){
						post.push_back(st.top());
						st.pop();
					}
					st.push(ss);
				}
			}
			if (i == s.size() - 1)
				post.push_back(to_string(num));
		}
		while(!st.empty()){
			post.push_back(st.top());
			st.pop();
		}
		for (int i = 0 ; i < post.size() ; i++){
			if (post[i]!=string("+") && post[i]!=string("-") && 
					post[i]!=string("*") && post[i]!=string("/")){
				st.push(post[i]);
			} else {
				int next = stoi(st.top());
				st.pop();
				int pre = stoi(st.top());
				st.pop();
				if (post[i] == string("+"))
					next = pre + next;
				else if (post[i] ==  string("-"))
					next = pre - next;
				else if (post[i] ==  string("*"))
					next = pre * next;
				else if (post[i] ==  string("/"))
					next = pre / next;
				st.push(to_string(next));
			}
		}
		return stoi(st.top());
	}
	bool greaterProi(string a, string b){
		if (b == string("+") || b==string("-"))
			return true;
		else {
			if (a==string("+") || a==string("-"))
				return false;
			else
				return true;
		}
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	Solution sol;
	cout<< sol.calculate("1+2-3*4+6/3");
	cout <<endl;

	return 0;
}

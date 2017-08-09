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
		vector<string> post;
		stack<string> st;
		string ss;
		int num = 0;
		bool numvalid = false;
		for (int i = 0 ; i < s.size() ; i++){
			if (s[i]>='0' && s[i]<='9'){
				num = num*10 + s[i] - '0';
				numvalid = true;
			} else if(s[i]=='+' || s[i]=='-'){
				if (numvalid)
					post.push_back(to_string(num));
				num = 0;
				numvalid = false;
				ss.clear();
				ss += s[i];
				if (st.empty() || st.top()==string("(")){
					st.push(ss);
				} else {
					post.push_back(st.top());
					st.pop();
					st.push(ss);
				}
			} else if(s[i] == '('){
				ss.clear();
				ss += s[i];
				st.push(ss);
			} else if (s[i] == ')'){
				if (numvalid)
					post.push_back(to_string(num));
				num = 0;
				numvalid = false;
				while(st.top()!=string("(")){
					post.push_back(st.top());
					st.pop();
				}
				st.pop();
			}
			if (i==s.size()-1 && numvalid)
					post.push_back(to_string(num));
		}
		while(!st.empty()){
			post.push_back(st.top());
			st.pop();
		}
		for (int i = 0 ; i < post.size() ; i++){
			if (post[i]!= string("+") && post[i]!=string("-")){
				st.push(post[i]);
			} else {
				int next = stoi(st.top()); st.pop();
				int pre = stoi(st.top()); st.pop();
				if (post[i] == string("+"))
					next = pre + next;
				else
					next = pre - next;
				st.push(to_string(next));
			}
		}
		return stoi(st.top());
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
	ret = sol.calculate("1+(2+3-1)+(1-3)");
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

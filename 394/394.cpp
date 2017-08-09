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
	string decodeString(string s){
		string ans;
		int num = 0, count; string tmp;
		stack<string> st;
		if (s.empty())
			return s;
		for (int i = 0 ; i < s.size() ; i++){
			if (s[i] >= '0' && s[i] <= '9' ){
				num = num* 10 + s[i] - '0';
			} else if (s[i] >= 'a' && s[i] <= 'z') {
				if (!st.empty() && st.top()!=string("[")){
					tmp = st.top();
					st.pop();
				} else
					tmp = string("");
				tmp += s[i];
				st.push(tmp);
			} else if (s[i] == '['){
				st.push(to_string(num));
				num = 0;
				string ss; ss += s[i];
				st.push(ss);
			} else {
				string ret;
				tmp = st.top(); st.pop();
				st.pop(); // remove [
				string cc = st.top(); st.pop();	count = stoi(cc);
				for (int i = 0 ; i < count; i++)
					ret+= tmp;
				if (!st.empty() && st.top()!=string("[")){
					string s2 = st.top(); st.pop();
					st.push(s2+ret);
				}else
					st.push(ret);
			}
		}
		return st.top();
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	string sa("3[a]2[bc]");
	string sb("3[a2[bc]]");
	string sc("2[ab]3[cd]ef");
	string sd("leetcode");
	Solution sol;
	vector<int> ret_vec;
//	cout << sol.decodeString(sa) << endl;
//	cout << sol.decodeString(sb) << endl;
//	cout << sol.decodeString(sc) << endl;
	cout << sol.decodeString("2[2[b]]") << endl;

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

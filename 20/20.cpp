#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	bool isValid(string s){
		stack<char> st;
		for (int i = 0 ; i < s.size() ; i++){
			if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
				st.push(s[i]);
			} else {
				if (st.empty())
					return false;
				if ((s[i] ==  ')' && st.top() == '(') ||
				     (s[i] == ']' && st.top() == '[') ||
				     (s[i] == '}' && st.top() == '{'))
					st.pop();
				else {
					return false;
				}
			}
		}
		return st.empty();
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
	cout << sol.isValid("(])") << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <unordered_set>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	string parseTernary(string exp) {
		stack<char> st;
		string ans;
		for (int i = 0 ; i < exp.size() ; i++){
			if (!st.empty() && st.top() == ':'){
				char right = exp[i];
				st.pop();
				char left = st.top();
				st.pop();st.pop();
				char bo = st.top();
				st.pop();
				if (bo == 'T')
					st.push(left);
				else
					st.push(right);
			} else
				st.push(exp[i]);
		}
		ans += st.top();
		return ans;	
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	Solution sol;
	vector<int> ret_vec;
	string ret;
	ret = sol.parseTernary("T?T?F:5:3");
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

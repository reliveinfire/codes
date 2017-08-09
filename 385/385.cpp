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
	NestedInteger deserialize(string s){
		stack<NestedInteger> st;
		int num = 0;
		NestedInteger tmp;
		if (s.empty())
			return NestedInteger();
		
		bool isNumber = 0;
		bool isNega = 0;
		for (int i = 0 ; i < s.size() ; i++){
			if (s[i] == '['){
				st.push(NestedInteger());
				isNumber = 0;
				isNega = 0;
			} else if (s[i]>= '0' && s[i] <= '9'){
				num = num*10 + s[i] - '0';
				isNumber = 1;
			} else if (s[i] == ',') {
				if (isNumber){
					if (isNega)
					st.top().add(NestedInteger(-num));
					else
					st.top().add(NestedInteger(num));
				}
				num = 0;
				isNumber = 0;
				isNega = 0;
			} else if (s[i] == ']'){
				if (isNumber){
					if (isNega)
					st.top().add(NestedInteger(-num));
					else
					st.top().add(NestedInteger(num));
				}
				if (i == s.size() -1)
					break;
				tmp = st.top();
				st.pop();
				st.top().add(tmp);
				isNumber = 0;
				isNega = 0;
			} else if (s[i] == '-'){
				isNega = 1;
			}
			if (i == s.size() - 1 && isNumber){
				tmp.setInteger(num);
				return tmp;
			}
		}
		return st.top();	
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
	ret = sol.
	ret_vec = sol.
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

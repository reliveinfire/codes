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
	bool isValidSerialization(string preorder){
		int idx = 0;
		vector<string> nodes;
		stack<string> st;
		while(true){
			int pos = preorder.find(string(","), idx);
			if (pos == string::npos){
				nodes.push_back(preorder.substr(idx, preorder.size() - idx));
				break;
			}
			nodes.push_back(preorder.substr(idx, pos - idx));
			idx = pos + 1;
		}
		for (int i = 0 ; i < nodes.size() ; i++){
			if (nodes[i] != string("#")){
				st.push(nodes[i]);
			} else {
				if (st.empty()){
					if (i == nodes.size() - 1)
						return true;
					else
						return false;
				}
				st.pop();
			}
		}
		return false;
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
	ret = sol.isValidSerialization("1,2,#,3,#,#,4,#,#");
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

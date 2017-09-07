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
#include "../helpers.cpp"
vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};


class Solution {
	public:
	int depthSum(vector<NestedInteger>& nestedList){
		vector<int> cnts;
		int ans = 0;
		int size = cnts.size();
		for (int i = 0 ; i < size ; i++){
			ans += (size - i) * cnts[i];
		}
		return getval(nl, 0);
	}
	void getval(vector<NestedInteger>& nl, int depth, vector<int>& cnts){
		if (depth == cnts.size())
			cnts.push_back(0);
		for (int i = 0 ; i < nl.size() ; i++){
			if (nl[i].isInteger())
				cnts[depth] += nl[i].getInteger();
			else
				getval(nl[i], depth+1, cnts);
		}
		return;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	string tre("1,#,3,2,#,#,4,#,5,#,#");
	Codec cc;
	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
	Solution sol;
	int ret;
	ret = sol.
	auto ret_vec = sol.
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

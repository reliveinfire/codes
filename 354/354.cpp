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

bool compare(pair<int,int>& a, pair<int,int>& b){
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}
class Solution {
	public:
	int maxEnvelopes(vector<pair<int, int>>& envelopes){
		vector<int> dp(envelopes.size(), 1);
		sort(envelopes.begin(), envelopes.end(), compare);
		for (int i = 0 ; i < dp.size() ; i++){
			for (int j = 0 ; j < i ; j++){
				if (envelopes[i].first > envelopes[j].first &&
					envelopes[i].second > envelopes[j].second)
					dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		return dp[dp.size()-1];
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

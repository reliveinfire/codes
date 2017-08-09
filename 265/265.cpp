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

class Solution {
	public:
	int minCostII(vector<vector<int>>& costs){
		vector<vector<int>> dp(costs.size(), vector<int>(costs[0].size()));
		vector<map<int,int>> vv(2);
		int idx = 0;
		for (int i = 0 ; i < costs[0].size() ; i++){
			dp[0][i] = costs[0][i];
			vv[idx][dp[0][i]] = i;
			if (vv[idx].size() > 2){
				auto it = vv[idx].end();
				it--;
				vv[idx].erase(it);
			}
		}
		for (int i = 1 ; i < costs.size() ; i++){
			int pre = idx;
			idx ^= 1;
			auto small = vv[pre].begin();
			auto big   = ++small;
			vv[idx].clear();
			for (int j = 0 ; j < costs[i].size() ; j++){
				if (j == small->second){
					dp[i][j] += big->first;
				} else 
					dp[i][j] += small->first;
				vv[idx][dp[i][j]] = j;
				if (vv[idx].size() > 2){
					auto it = vv[idx].end();
					it--;
					vv[idx].erase(it);
				}
			}
		}

		return vv[idx].begin()->first;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	Solution sol;
	vector<int> ret_vec;
	int ret;
	map<int,string> mm = {{7,"77"}, {6,"66"},{9,"99"},{8,"88"}};
	auto it = mm.end();
	it--;
	cout << it->first <<":"<< it->second<<endl;
	mm.erase(it);
	it = mm.end();
	it--;
	cout << it->first <<":"<< it->second<<endl;

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

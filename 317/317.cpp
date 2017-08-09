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
	int findBuilding(vector<vector<int>>& grid){
		vector<vector<unordered_map<pair<int,int>,int>>> dp(grid.size(), vector<unordered_map<pair<int,int>>,int>(grid[0].size()));
		queue<pair<int,int>> qu;
		int direct[4][2] = {{1,0},{-1,0},{0, 1},{0,-1}};
		int all = 0;
		for (int i = 0 ; i < grid.size() ; i++){
			for (int j = 0 ; j < grid[0].size() ; j++){
				if (grid[i][j] == 1){
					pair<int,int> tmp(i,j);
					qu.push(tmp);
					dp[i][j][tmp] = 0;
				}
			}
		}
		all = qu.size();
		int ans = 0;
		while(!qu.empty()){
			int sz = qu.size();
			for (int i = 0 ; i < sz ; i++){
				pair<int,int> cur = qu.front();
				qu.pop();
				if (dp[cur.first][cur.second].size() == all){
					for (auto iter = dp[cur.first][cur.second].begin() ; iter != dp[cur.first][cur.second].end() ; iter++){
						ans += iter->second;
						return ans;
					}
				} else {
					for (int j = 0 ; j < 4 ; j++){
						int nr = cur.first + direct[j][0];
						int nc = cur.second + direct[j][1];
					}
				}
			}
		}
		
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

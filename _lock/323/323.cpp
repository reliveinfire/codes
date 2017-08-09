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
	int countComponents(int n, vector<pair<int, int> >& edges){
		int ans = 0;
		vector<int> visit(n, 0);
		unordered_map<int, unordered_set<int>> eg;
		for (int i = 0 ; i < edges.size() ; i++){
				eg[edges[i].first].insert(edges[i].second);
				eg[edges[i].second].insert(edges[i].first);
		}
		for (int i = 0 ; i < visit.size() ; i++){
			if (!visit[i]){
				ans++;
				dfs(i, visit, eg);
			}
		}
		return ans;
	}
	void dfs(int node, vector<int>& visit, unordered_map<int,unordered_set<int>>& eg){
		if (visit[node])
			return;
		visit[node] = 1;
		auto iter = eg.find(node);
		if (iter == eg.end())
			return;

		for (auto tt = iter->second.begin() ; tt != iter->second.end() ; tt++)
			dfs(*tt, visit, eg);
		return;
	}
};

int toIdx(int row, int col, int n){
	return row*n + col;
}
int find(int id, vector<int>& roots){
	while(id != roots[id]){
		roots[id] = roots[roots[id]];
		id = root[id];
	}
	return id;
}
int lands(vector<pair<int,int>>& nums, int m, int n)
{
	vector<int> roots(m*n, -1);
	int ans = 0;
	int direct[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
	for (int i = 0 ; i < nums ; i++){
		int cr = nums[i].first;
		int cc = nums[i].second;
		int cidx = toIdx(cr,cc,n)
		int theroot = -1;
		for (int j = 0 ; j < 4 ; j++){
			int nr = cr + direct[j][0];
			int nc = cc + direct[j][1];
			int nidx = toIdx(nr,nc,n);
			if (nr >= 0 && nr < m && nc >= 0 && nc < n){
				if (roots[nidx]!= -1){
					if (theroot == -1){
						roots[cidx] = nidx;
						theroot = find(cidx);
					} else {
						int other = find(nidx);
						if (other != theroot){
							roots[other] = theroot;
							ans--;
						}
					}
				}
			}
		}
		if (theroot == -1){
			roots[cidx] = toIdx(cr,cc,n);
			ans++;
		}
	
	}
	return ans;
}
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	vector<pair<int,int>> edges;
	edges.push_back(pair<int,int>(0,1));
	edges.push_back(pair<int,int>(1,2));
	edges.push_back(pair<int,int>(3,4));
	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
	Solution sol;
	int ret = sol.countComponents(5, edges);
	cout << ret << "\n";

	cout <<endl;

	return 0;
}

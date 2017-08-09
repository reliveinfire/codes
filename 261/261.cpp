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
	bool validTree(int n, vector<pair<int, int>>& edges){
		unordered_map<int, set<int>> edge;
		vector<int> visited(n, 0);
		for (pair<int,int> p : edges){
			edge[p.first].insert(p.second);
			edge[p.second].insert(p.first);
		}
		bool ret = dfs(-1, 0, visited, edge);
		if (!ret)
			return false;
		for (int i = 0 ; i < visited.size() ; i++){
			if (!visited[i])
				return false;
		}
		return true;
	}
	bool dfs(int pre, int curr, vector<int>& visited, unordered_map<int, set<int>>& edge)
	{
		if (visited[curr])
			return false;
		visited[curr] = true;
		for (auto it = edge[curr].begin() ; it != edge[curr].end() ; it++){
			if (*it!=pre){
				bool ret = dfs(curr, *it, visited, edge);
				if (!ret)
					return false;
			}
		}
		return true;
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
	vector<pair<int,int>> edges;
	edges.push_back(pair<int,int>(0,1));
	edges.push_back(pair<int,int>(1,2));
	edges.push_back(pair<int,int>(2,3));
	edges.push_back(pair<int,int>(1,4));
	edges.push_back(pair<int,int>(1,3));
	ret = sol.validTree(5, edges);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

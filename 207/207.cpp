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
#include <list>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	bool canFinish(int numCourses, vector<pair<int, int>>& pre){
		vector<bool> visit(numCourses, false);
		vector<bool> currStack(numCourses, false);
		vector<vector<int> > adj(numCourses);
		if (numCourses <= 1)
			return true;
		for (int i = 0 ; i < pre.size() ; i++){
			pair<int,int> t = pre[i];
			adj[t.first].push_back(t.second);
		}
		for (int i = 0 ; i < numCourses ; i++){
			if (!dfs(i, adj, visit, currStack))
				return false;
		}
		return true;
	}

	bool dfs(int node, vector<vector<int> >& adj, vector<bool>& visit, vector<bool>& currStack){
		bool ret;
		if (!visit[node]){
			visit[node] = true;
			currStack[node] = true;
			for (int i = 0 ; i < adj[node].size() ; i++){
				int nn = adj[node][i];
				if (currStack[nn]){
					ret = false;
					break;
				}
				currStack[nn] = true;
				ret = dfs(nn, adj, visit, currStack);
				currStack[nn] = false;
				if (!ret)
					break;
			}
			currStack[node] = false;
			if (!ret)
				return false;
		}
		return true;
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
	vector<pair<int,int> > pre;
	pre.push_back(pair<int,int>(0,1));
	pre.push_back(pair<int,int>(1,0));
	cout << sol.canFinish(2,pre) << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

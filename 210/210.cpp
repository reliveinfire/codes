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
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& pre){ 
		vector<int> indirect(numCourses, 0);
		vector<vector<int> > adj(numCourses);
		vector<int> ans;
		queue<int> qu;
		if (numCourses == 1){
			ans.push_back(0);
			return ans;
		}
		for (int i = 0 ; i < pre.size() ; i++){
			pair<int,int> t = pre[i];
			adj[t.second].push_back(t.first);
			indirect[t.first]++;
		}
		for (int i = 0 ; i < numCourses ; i++){
			if (indirect[i] == 0){
				qu.push(i);
			}
		}
		while(!qu.empty()){
			int node = qu.front();
			ans.push_back(node);
			qu.pop();
			for (int i = 0 ; i < adj[node].size() ; i++){
				int next = adj[node][i];
				indirect[next]--;
				if (indirect[next] == 0)
					qu.push(next);
			}
		}
		if (ans.size() != numCourses)
			ans.clear();
			
		return ans;
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
	pre.push_back(pair<int,int>(2,0));
	pre.push_back(pair<int,int>(2,1));
	ret_vec = sol.findOrder(3, pre);
//	cout << sol.canFinish(2,pre) << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

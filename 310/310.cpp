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
		vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges){
			vector<int> result;
			if (n==0)
				return result;
			// 漂亮!, 使用set
			vector< set<int> > adj(n);
			for (int i = 0 ; i < edges.size() ; i++){
				pair<int,int> tt = edges[i];
				adj[tt.first].insert(tt.second);
				adj[tt.second].insert(tt.first);
			}
			vector<int> degree(n,0);
			for (int i = 0 ; i < adj.size() ; i++){
					degree[i] = adj[i].size();
			}
			while (n > 2){
				vector<int> remove;
				int dcount = 0;
				for (int i = 0 ; i < degree.size() ; i++){
					if (degree[i] == 1){
						degree[i] = -1;
						remove.push_back(i);
						dcount++;
					}
				}
				for (int i = 0 ; i < remove.size() ; i++){
					int rr = remove[i];
					for (set<int>::iterator iter = adj[rr].begin();
						iter != adj[rr].end() ; iter++){
						degree[*iter]--;
					}
				}
				n = n - dcount;
			}
			for (int i = 0 ; i < degree.size() ; i++){
				if (degree[i] >= 0)
					result.push_back(i);
			}
			return result;
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
	vector< pair<int,int> > edges;
	edges.push_back(pair<int,int>(1,0));
	edges.push_back(pair<int,int>(1,2));
	edges.push_back(pair<int,int>(1,3));
	int ret;
	ret_vec = sol.findMinHeightTrees(4, edges);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

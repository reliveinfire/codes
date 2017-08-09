#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};
class Solution {
	public:
	map<int, UndirectedGraphNode* > visit;
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node){
		return dfs(node);
	}

	UndirectedGraphNode *dfs(UndirectedGraphNode* orig){
		if (orig==NULL)
			return NULL;
		if (visit.find(orig->label)!=visit.end())
			return visit.find(orig->label)->second;
			
		UndirectedGraphNode *gen = new UndirectedGraphNode(orig->label);
		visit[gen->label] = gen;

		for (int i = 0 ; i < orig->neighbors.size() ; i++){
			UndirectedGraphNode *next = orig->neighbors[i];
			UndirectedGraphNode *clone = dfs(orig);
			gen->neighbors.push_back(clone);
		}
		return gen;
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
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

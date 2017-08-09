#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <unordered_set>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	vector<double> calcEquation(vector<pair<string, string>> equations,
			vector<double>& values, vector<pair<string, string>> queries)
	{
		unordered_map<string, vector<pair<string,double>>> adj;
		unordered_set<string> nodes;
		vector<double> ans;
		pair<string,double> tmp;
		for (int i = 0 ; i < equations.size() ; i++){
			tmp.first = equations[i].first;
			tmp.second = values[i];
			adj[equations[i].second].push_back(tmp);
			
			tmp.first = equations[i].second;
			tmp.second = 1 / values[i];
			adj[equations[i].first].push_back(tmp);
			nodes.insert(equations[i].first);
			nodes.insert(equations[i].second);
		}
		double tv;
		unordered_set<string> visit;
#if 0
		for (int i = 0 ; i < queries.size() ; i++){
			tv = -1;
			visit.clear();
			if (nodes.count(queries[i].second)!= 0)
				helper(queries[i].second, queries[i].first, tv, 1, adj, visit);
			ans.push_back(tv);
		}
#else
		double tns = 0;
		for (int i = 0 ; i < queries.size() ; i++){
			visit.clear();
			tns = dfs(queries[i].second,  queries[i].first, adj, visit, nodes);
			if (tns == 0)
				ans.push_back(-1);
			else
				ans.push_back(tns);
		}
#endif
		return ans;
	}
	void helper(string from, string to, double& ans,  double val, 
	unordered_map<string, vector<pair<string,double>>>& adj, unordered_set<string>& visit)
	{
//		cout << from <<"  to  " << to << endl;
		if (ans!=-1)
			return;
		if (from == to){
			ans = val;
			return;
		}
		visit.insert(from);
		vector<pair<string,double>> next = adj[from];
		double tmp;
		for ( int i = 0; i < next.size() ; i++){
			if (visit.count(next[i].first)== 0 )
			{
				tmp = val * next[i].second;
				helper(next[i].first, to, ans, tmp, adj, visit);
			}
		}
		visit.erase(from);
		return;
	}
	double dfs(string from, string to, unordered_map<string, vector<pair<string,double>>>& adj,
			unordered_set<string>& visit, unordered_set<string>& nodes)
	{
		double ret = 0;
		if (from == to){
			if (nodes.count(from)!= 0)
				return 1;
			else
				return 0;
		}
		visit.insert(from);
		vector<pair<string,double>> next = adj[from];
		for (int i = 0 ; i < next.size() ; i++) {
			if (visit.count(next[i].first)== 0){
				ret = dfs(next[i].first, to, adj, visit, nodes);
				if (ret!=0){
					ret = ret * next[i].second;
					break;
				}
			}
		}
	
		visit.erase(from);
		return ret;
	}
};

#define genVector(data, array) vector<double> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<pair<string,string>> equ;
	vector<pair<string,string>> qu;
#if 1
	double A[] = {2,3};
	equ.push_back(pair<string,string>(string("a"),string("b")));
	equ.push_back(pair<string,string>(string("b"),string("c")));
	genVector(da, A);
	qu.push_back(pair<string,string>(string("a"),string("c")));
	qu.push_back(pair<string,string>(string("b"),string("a")));
	qu.push_back(pair<string,string>(string("a"),string("e")));
	qu.push_back(pair<string,string>(string("a"),string("a")));
	qu.push_back(pair<string,string>(string("x"),string("x")));
#else
	double A[] = {1.5,2.5};
	equ.push_back(pair<string,string>(string("a"),string("b")));
	equ.push_back(pair<string,string>(string("b"),string("c")));
	genVector(da, A);
//	qu.push_back(pair<string,string>(string("a"),string("c")));
	qu.push_back(pair<string,string>(string("c"),string("b")));
#endif
	


	Solution sol;
	vector<double> ret_vec;
	ret_vec =  sol.calcEquation(equ, da, qu);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

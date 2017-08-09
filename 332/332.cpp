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
	map<string, vector<string> > adj;
	map<string, vector<bool> > visit;
	vector<string> tmp;
	vector<string> result;
	bool found;
	vector<string> findItinerary(vector<pair<string, string>> tickets){
		for (int i = 0 ; i < tickets.size() ; i++){
			adj[tickets[i].first].push_back(tickets[i].second);
			visit[tickets[i].first].push_back(false);
		}
		map<string, vector<string> >::iterator iter;
		for (iter = adj.begin() ; iter != adj.end() ; iter++){
			sort(iter->second.begin(), iter->second.end());
		}
		found = false;
		tmp.push_back("JFK");
		helper("JFK", tickets.size());
		return result;
	}
	void helper(string curr, int N)
	{
		if (found)
			return;
		if (N==0){
			found = true;
			for (int i = 0 ; i < tmp.size() ; i++)
				result.push_back(tmp[i]);
			return;
		}
		vector<string> depart = adj[curr];
		for (int i = 0 ; i < depart.size() ; i++){
			if (!visit[curr][i]){
				tmp.push_back(depart[i]);
				visit[curr][i] = true;
				helper(depart[i], N-1);
				tmp.pop_back();
				visit[curr][i] = false;
			}
		}
		return;
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
	vector<string> ret_vec;
	int ret;
	vector<pair<string,string> > tickets;
#if 0
	tickets.push_back(pair<string,string>("MUC","LHR"));
	tickets.push_back(pair<string,string>("JFK","MUC"));
	tickets.push_back(pair<string,string>("SFO","SJC"));
	tickets.push_back(pair<string,string>("LHR","SFO"));
#else
	tickets.push_back(pair<string,string>("JFK","SFO"));
	tickets.push_back(pair<string,string>("JFK","ATL"));
	tickets.push_back(pair<string,string>("SFO","ATL"));
	tickets.push_back(pair<string,string>("ATL","JFK"));
	tickets.push_back(pair<string,string>("ATL","SFO"));
#endif
	ret_vec = sol.findItinerary(tickets);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
	struct State {
		int found;
		double val;
	};
         vector<double> calcEquation(vector<pair<string, string>> equ,
                        vector<double>& values, vector<pair<string, string>> qs){
			vector<double> ans(qs.size());
			unordered_map<string, unordered_map<string, double>> edges;
			for (int i = 0 ; i < equ.size() ; i++){
				edges[equ[i].first][equ[i].second] = 1 / values[i];
				edges[equ[i].second][equ[i].first] = values[i];
			}
			for (int i = 0 ; i < qs.size() ; i++){
				pair<string,string> tmp = qs[i];
				unordered_set<string> visited;
				if (edges.count(tmp.first)==0 || edges.count(tmp.second)==0)
					ans[i] = -1;
				else if (tmp.first == tmp.second)
					ans[i] = 1;
				 else {
					State sta = dfs(tmp.second, tmp.first, visited, edges);
					if (sta.found)
						ans[i] = sta.val;
					else
						ans[i] = -1;
				}
			}
			return ans;
        }
	State dfs(string curr, string end, unordered_set<string>& visited,
		unordered_map<string, unordered_map<string, double>>& edges){
		if (curr==end)
			return {1, 1};
		visited.insert(curr);
		auto eg = edges[curr];
		for (auto iter = eg.begin() ; iter!=eg.end() ; iter++){
			if (visited.count(iter->first)==0){
				State sta = dfs(iter->first, end, visited, edges);
				if (sta.found){
					return {1, iter->second * sta.val};
				}
			}
		}
		visited.erase(curr);
		return {0, 1};
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
	int ret;
	ret = sol.
	auto ret_vec = sol.
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

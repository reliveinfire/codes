#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
         int networkDelayTime(vector<vector<int>>& times, int N, int K){
	 	unordered_map<int, vector<pair<int,int>> > adjs;
		for (int i = 0 ; i < times.size() ; i++){
			int src = times[i][0];
			int dst = times[i][1];
			int t = times[i][2];
			adjs[src].push_back(make_pair(dst,t));
		}
		unordered_map<int,int> tt;
		queue<int> qu;
		tt[K] = 0;
		qu.push(K);
		while(!qu.empty()){
			auto& v = adjs[qu.front()];
			int now = tt[qu.front()];
			qu.pop();
			for (int i = 0 ; i < v.size() ; i++){
				int dst = v[i].first;
				int t = v[i].second;
				if (tt.count(dst)==0 || now + t < tt[dst]) {
					tt[dst] = now + t;
					qu.push(dst);
				} 
			}
		}
		if (tt.size()!=N)
			return -1;
		int res = INT_MIN;
		for (auto iter = tt.begin() ; iter != tt.end() ; iter++){
			if (iter->second > res)
				res = iter->second;
		}
		return res;
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

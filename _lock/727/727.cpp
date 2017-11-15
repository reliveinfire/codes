#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        string minWindow(string S, string T){
		string res;
		unordered_map<char, int> lastpos;
		unordered_map<char, vector<int>> cc;
		vector<int> dist(T.size(), 0);
		for (int i = 0 ; i < T.size() ; i++){
			cc[T[i]].push_back(i);
		}
		for (int i = 0 ; i < S.size() ; i++){
			if (cc.count(S[i])!=0){
				vector<int> tmp = cc[S[i]];
				char cur = S[i];
				for (int j = tmp.size() - 1 ; j>= 0 ; j--){
					if (tmp[j]==0){
						dist[0] = 1;
						//cout << cur << endl;
					} else {
						if (dist[tmp[j]-1]!=0){
							dist[tmp[j]] = dist[tmp[j]-1] + i - lastpos[T[tmp[j]-1]];
							//printf("i:%d pos:%d dist[pos]:%d cur:%c\n",i,
							//		tmp[j], dist[tmp[j]], cur);
						}
					}
					if (tmp[j]==T.size()-1 && dist.back() != 0){
						int idx = i - dist.back() + 1;
						string tmp = S.substr(idx, dist.back());
						if (res.size() == 0 || res.size() > tmp.size())
							res = tmp;
					}
				}
				lastpos[S[i]] = i;
			}
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
	auto ret_vec = sol.minWindow("abcdebdde", "bde");
	//auto ret_vec = sol.minWindow("abcdebbdde", "bbde");
	//auto ret_vec = sol.minWindow("abcdebbdde", "b");
	cout << ret_vec << endl;
	cout <<endl;

	return 0;
}

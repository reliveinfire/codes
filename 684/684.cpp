#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        vector<int> findRedundantConnection(vector<vector<int>>& edges){
		unordered_map<int,int> mm;
		vector<int> roots;
		vector<int> ret;
		for (int i = 0 ; i < edges.size() ; i++){
			int a = edges[i][0];
			int b = edges[i][1];
			int n;
			if (mm.count(a)==0){
				n = mm.size();
				mm[a] = n;
				roots.push_back(n);
			}
			if (mm.count(b)==0){
				n = mm.size();
				mm[b] = n;
				roots.push_back(n);
			}
			int ra = find(roots, mm[a]);
			int rb = find(roots, mm[b]);
			if (ra!=rb){
				roots[ra] = roots[rb];
			} else{
				ret = edges[i];
				break;
			}
		}
		return ret;
        }
	int find(vector<int>& roots, int r){
		while(roots[r]!=r){
			r = roots[r];
		}
		return r;
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

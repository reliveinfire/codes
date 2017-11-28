#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        bool areSentencesSimilar(vector<string>& words1, vector<string>& words2,
	vector<pair<string, string>> pairs){
		unordered_map<string, unordered_set<string>> mm;
		for(auto& pp : pairs){
			mm[pp.first].insert(pp.second);
			mm[pp.second].insert(pp.first);
		}
		int m = words1.size();
		int n = words2.size();
		if (m!=n)
			return false;
		for (int i = 0 ; i < m ; i++){
			auto sim = mm[words1[i]];
			if (sim.count(words2[i])!=0 || words1[i]==words2[i])
				continue;
			return false;
		}
		return true;
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

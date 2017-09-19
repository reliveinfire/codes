#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        string replaceWords(vector<string>& dict, string sentence){
		string res;
		unordered_set<string> dd;
		for (string s : dict)
			dd.insert(s);
		stringstream ss(sentence);
		string token;
		while(getline(ss, token, ' ')){
			string tmp;
			int i = 0;
			for (; i < token.size() ; i++){
				tmp = token.substr(0, i+1);
				if (dd.count(tmp)!=0){
					res += tmp;
					break;
				}
			}
			if (i==token.size())
				res += token;
			res += " ";
		}
		return res.substr(0, res.size()-1);
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

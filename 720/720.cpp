#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
bool comp(const string& a, const string& b){
	if (a.size() ==  b.size())
		return a < b;
	else
		return a.size() < b.size();
};
struct Node{
	Node* next[26];
	Node(){
		for (int i = 0 ; i < 26 ; i++)
			next[i] = NULL;
	}
};
class Solution {
        public:
        string longestWord(vector<string>& words){
		string res;
		sort(words.begin(), words.end(), comp);
		Node* root = new Node();
		for (string str : words){
			Node* idx = root;
			for (int i = 0 ; i < str.size() ; i++){
				if (idx->next[str[i]-'a']!=NULL){
					idx = idx->next[str[i]-'a'];
				} else {
					if (i==str.size()-1){
						idx->next[str[i]-'a'] = new Node();
						idx = idx->next[str[i]-'a'];
						if (str.size() > res.size())
							res = str;
					} else
						break;
				}
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
	int ret;
	ret = sol.
	auto ret_vec = sol.
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

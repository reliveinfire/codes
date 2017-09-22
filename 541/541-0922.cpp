#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        string reverseStr(string s, int k){
		int idx = 0;
		if (k==1)
			return s;
		while(idx<s.size()){
			int rr = min(idx+k-1, (int)s.size()-1);
			int ll = idx;
			while(ll<rr){
				char t = s[rr];
				s[rr] = s[ll];
				s[ll] = t;
				ll++;
				rr--;
			}
			idx += 2*k;
		}
		return s;
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

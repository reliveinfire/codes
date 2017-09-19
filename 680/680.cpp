#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        bool validPalindrome(string s){
		if (s.empty())
			return true;
		return helper(s, 0, s.size() - 1, 1);
        }
	bool helper(string s, int ll, int rr, int del){
		while (ll<rr){
			if (s[ll] == s[rr]){
				ll++;
				rr--;
			} else {
				if (del)
					return helper(s, ll+1, rr, 0) || helper(s, ll, rr-1, 0);
				else
					return false;
			}
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

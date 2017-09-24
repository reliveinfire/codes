#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        vector<TreeNode*> generateTrees(int n){
		return helper(1, n);
        }
	vector<TreeNode*> helper(int ll, int rr){
		vector<TreeNode*> res;
		TreeNode* tmp;
		if (ll==rr){
			tmp = new TreeNode(ll);
			res.push_back(tmp);
			return res;
		}
		if (ll > rr)
			return res;
		for (int i = ll ; i <= rr ; i++){
			vector<TreeNode*> left = helper(ll, i-1);
			vector<TreeNode*> right = helper(i+1, rr);
			if (left.empty()){
				for (int m = 0 ; m < right.size() ; m++){
					tmp = new TreeNode(i);
					tmp->right = right[m];
					res.push_back(tmp);
				}
			} else if (right.empty()){
				for (int m = 0 ; m < left.size() ; m++){
					tmp = new TreeNode(i);
					tmp->left = left[m];
					res.push_back(tmp);
				}
			} else {
				for (int m = 0 ; m < left.size() ; m++){
					for (int n = 0 ; n < right.size() ;n++)	{
						tmp = new TreeNode(i);
						tmp->left = left[m];
						tmp->right = right[n];
						res.push_back(tmp);
					}
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

#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        int pathSum(TreeNode* root, int sum){
		int res = 0;
		unordered_map<int,int> presum;
		helper(root, sum, 0, res, presum);
		return res;
        }
	void helper(TreeNode* node, int sum, int total, int& res, unordered_map<int,int>& presum){
		if (node==NULL)
			return;
		int now = total + node->val;
		if (now==sum)
			res++;
		auto iter = presum.find(now-sum);
		if (iter!=presum.end())
			res += iter->second;
		presum[now]++;
		helper(node->left, sum, now, res, presum);
		helper(node->right, sum, now, res, presum);
		presum[now]--;
		return;
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

#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return helper(nums, 0, nums.size() - 1);
        }
	TreeNode* helper(vector<int>& nums, int ll, int rr)
	{
		if (ll>rr)
			return NULL;
		int maxpos = -1;
		int maxval = INT_MIN;
		for (int i = ll ; i <= rr ; i++){
			if (nums[i]>maxval){
				maxpos = i;
				maxval = nums[i];
			}
		}
		TreeNode* node = new TreeNode(nums[maxpos]);
		node->left = helper(nums, ll, maxpos-1);
		node->right = helper(nums, maxpos+1, rr);
		return node;
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

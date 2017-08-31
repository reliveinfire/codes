#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
	int ans;
        int widthOfBinaryTree(TreeNode* root){
		unordered_map<int, pair<int,int>> tb;
		ans = INT_MIN;
		helper(root, 1, 1, tb);
		return ans;
        }

	void helper(TreeNode* node, int pos, int height, unordered_map<int, pair<int,int>>& tb)
	{
		if (node==NULL)
			return;
		if (tb.count(height)==0)
			tb[height] = pair<int,int>(pos,pos);
		else {
			pair<int,int> tmp = tb[height];
			tmp.first = min(tmp.first, pos);
			tmp.second = max(tmp.second, pos);
			tb[height] = tmp;
		}
		ans = max(ans, tb[height].second - tb[height].first + 1);
		helper(node->left, 2*pos-1, height+1, tb);
		helper(node->right, 2*pos, height+1, tb);
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

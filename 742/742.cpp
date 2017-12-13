#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
struct State{
	int height;
	int node;
};
class Solution {
        public:
        int findClosestLeaf(TreeNode* root, int k){
		vector<int> parents;
		vector<int> tmp;
		unordered_map<int, State> mheight;
		getheight(root, mheight);
		traversal(root, k, tmp, parents);
		int ans = mheight[k].node;
		int minh = mheight[k].height;
		int dist = 1;
		while(!parents.empty()){
			int nn = parents.back();
			parents.pop_back();
			if (dist + mheight[nn].height < minh){
				minh = dist + mheight[nn].height;
				ans = mheight[nn].node;
			}
			dist++;
		}
		return ans;
	}
	State getheight(TreeNode* node, unordered_map<int, State>& mem){
		if (!node->left && !node->right){
			mem[node->val] = {1,node->val};
			return mem[node->val];
		}
		State ll = {INT_MAX, INT_MAX};
		State rr = {INT_MAX, INT_MAX};
		if (node->left)
			ll = getheight(node->left, mem);
		if (node->right)
			rr = getheight(node->right, mem);
		if (rr.height < ll.height)
			ll = rr;
		ll.height++;
		mem[node->val] = ll;
		return mem[node->val];
	}

	void traversal(TreeNode* node, int k, vector<int>& tmp, vector<int>& parents){
		if (!parents.empty())
			return;
		if (!node)
			return;
		if (node->val==k){
			parents = tmp;
			return;
		}
		tmp.push_back(node->val);
		traversal(node->left, k, tmp, parents);
		traversal(node->right, k, tmp, parents);
		tmp.pop_back();
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

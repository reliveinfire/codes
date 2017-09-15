#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums){
		vector<vector<int>> res;
		vector<int> st;
		helper(nums, 0, st, res);
		return res;
        }
	void helper(vector<int>& nums, int cur, vector<int>& st, vector<vector<int>>& res)
	{
		unordered_set<int> used;
		res.push_back(st);

		for (int i = cur ; i < nums.size() ; i++){
			if (used.count(nums[i])==0){
				used.insert(nums[i]);
				st.push_back(nums[i]);
				helper(nums, i+1, st, res);
				st.pop_back();
			}
		}
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

#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        int dominantIndex(vector<int>& nums){
		int m = nums.size();
		if (m==1)
			return 0;
		int max_idx, second_idx;
		if (nums[0] > nums[1])
			max_idx = 0;
		else
			max_idx = 1;
		second_idx = max_idx^0x1;
		for (int i = 2 ; i < m ; i++){
			if (nums[i] >  nums[max_idx]){
				second_idx = max_idx;
				max_idx = i;
			} else if (nums[i] > nums[second_idx]){
				second_idx = i;
			}
		}
		if (nums[max_idx] >= nums[second_idx]*2)
			return max_idx;
		return -1;
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

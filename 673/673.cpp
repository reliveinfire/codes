#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        int findNumberOfLIS(vector<int>& nums){
		vector<int> dp(nums.size(), 1);
		vector<int> dc(nums.size(), 1);
		int cm = 1;
		for (int i = 0 ; i < nums.size() ; i++){
			for (int j = i - 1; j >= 0 ; j--){
				if (nums[i] > nums[j]){
					if (dp[j] + 1 > dp[i]){
						dc[i] = dc[j];
						dp[i] = dp[j]+1;
						cm = max(cm, dp[i]);
					} else if (dp[j]+1 == dp[i]){
						dc[i] += dc[j];
					}
				}
			}
		}
		int res = 0;
		for (int i = 0 ; i < dp.size() ; i++){
			if (dp[i] == cm){
				res += dc[i];
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

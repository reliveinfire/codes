#include "../helpers.cpp"

bool compare(const vector<int>& va, const vector<int>& vb){
	if (va[0] == vb[0]){
		return va[1] > vb[1];
	} else
		return va[0] < vb[0];
};
class Solution {
        public:
       	int findLongestChain(vector<vector<int>>& pairs){
		int ans = 1;
		sort(pairs.begin(), pairs.end(), compare);
		vector<int> dp(pairs.size(), 1);
		for (int i = 1 ; i < pairs.size() ; i++){
			for (int j = i - 1 ; j >= 0 ; j--){
				if (pairs[i][0] > pairs[j][1]){
					dp[i] = max(dp[i], dp[j]+1);
				}
			}
			ans = max(ans, dp[i]);
		}
		return ans;
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

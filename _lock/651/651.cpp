#include "../../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        int max_4kb(int n){
		vector<int> dp(n+1, INT_MAX);
		dp[0] = 0;
		for (int i = 1 ; i <= n ; i++){
			dp[i] = max(dp[i], dp[i-1]+1);
			if (i-2 > 0){
				int k = i - 2;
				for (int x = 1 ; x < k ; x++){
					int y = k - x;
					dp[i] = max(dp[i], dp[x]*y);
				}
			}
		}
		return dp[n];
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

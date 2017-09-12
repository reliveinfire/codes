#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        int countNumbersWithUniqueDigits(int n){
		vector<int> dp(n+1);
		if (n==0)
			return 1;
		if (n==1)
			return 10;
		if (n==2)
			return 91;
		dp[1] = 10;
		dp[2] = 9*9;
		int res = dp[1] + dp[2];
		int mul = 8;
		for (int i = 3 ; i <= n ; i ++){
			if (mul == 0)
				break;
			dp[i] = dp[i-1] * mul;
			res += dp[i];
			mul--;
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

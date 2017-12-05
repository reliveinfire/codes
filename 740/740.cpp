#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        int deleteAndEarn(vector<int>& nums){
		if (nums.empty())
			return 0;
		map<int,int> mm;
		for (int ii : nums)
			mm[ii]++;
		int n = mm.size();
		vector<vector<int>> dp(mm.size(), vector<int>(2, 0));
		auto iter = mm.begin();
		for (int i = 0 ; i < n ; iter++, i++){
			if (i==0){
				dp[i][1] = iter->first * iter->second;
			} else {
				dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
				if (prev(iter)->first+1 != iter->first){
					dp[i][1] = dp[i][0] + iter->first * iter->second;
				} else {
					dp[i][1] = dp[i-1][0] + iter->first * iter->second;
				}
			}
		}
		return max(dp[n-1][0], dp[n-1][1]);
        }
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {2,2,3,3,3,4};
	Solution sol;
	int ret;
	ret = sol.deleteAndEarn(A);
	cout << ret << "\n";
	return 0;
}

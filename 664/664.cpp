#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        int strangePrinter(string s){
		vector<vector<int>> dp(100, vector<int>(100));
		if (s.empty())
			return 0;
			
		for (int j = 0 ; j < s.size() ; j++){
			for (int i = j ; i >= 0 ; i--){
				if (i==j){
					dp[i][j] = 1;
				} else {
					dp[i][j] =  dp[i][j-1] + 1;
					for (int m = i ; m < j ; m++){
						if (s[m]==s[j]){
							dp[i][j] = min(dp[i][j],
									dp[i][m] + dp[m+1][j-1]);
						}
					}
				}
			}
		}
		return dp[0][s.size()-1];
        }
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	Solution sol;
	int ret;
//	ret = sol.strangePrinter("aaabbb");
//	ret = sol.strangePrinter("aaba");

//	ret = sol.strangePrinter("baab"); //ans=2
	//ret = sol.strangePrinter("baab"); //ans=2
	ret = sol.strangePrinter("aaabbbbaaaab");
	cout << ret << "\n";


	return 0;
}

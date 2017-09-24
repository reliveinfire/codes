#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        bool isInterleave(string s1, string s2, string s3){
		int m = s1.size();
		int n = s2.size();
		if (m+n != s3.size())
			return false;
		vector<vector<int>> dp(m+1, vector<int>(n+1));
		for (int i = 0 ; i <= m ; i++){
			for (int j = 0 ; j <= n ; j++){
				cout << i << ":" << j << endl;
				if (i==0 && j==0)
					dp[i][j] = 1;
				if (j!=0){
					if (dp[i][j-1] && s2[j-1]==s3[i+j-1])
						dp[i][j] = 1;
				} 
				if (i!=0){
					if (dp[i-1][j] && s1[i-1]==s3[i+j-1])
						dp[i][j] = 1;
				}
			}
		}
		return dp[m][n];
        }
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	string s1("a");
	string s2("b");
	string s3("ab");
	Solution sol;
	int ret;
	ret = sol.isInterleave(s1,s2,s3);
	cout << ret << "\n";


	return 0;
}

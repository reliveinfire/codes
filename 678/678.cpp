#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        bool checkValidString(string s){
		if (s.empty())
			return 1;
		vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
		for (int j = 0 ; j < s.size() ; j++){
			for (int i = j ; i>=0 ; i--){
				if (i==j){
					if (s[i]=='*')
						dp[i][j] = 1;
				} else if (i+1==j){
					if (isValid(s, i, j))
					     dp[i][j] = 1;
				} else {
					if (dp[i+1][j-1]){
						if (isValid(s,i,j))
							dp[i][j]=1;
					}
#if 0
					if (dp[i][j-2]){
						if (isValid(s, j-1, j))
							dp[i][j]=1;
					}
					if (dp[i+2][j]){
						if (isValid(s,i,i+1))
							dp[i][j] = 1;
					}
					if ((dp[i+1][j] && s[i]=='*' || (dp[i][j-1]&&s[j]=='*')))
						dp[i][j]=1;
#else
				for (int k = i ; k < j ; ++k){
					if (dp[i][k] && dp[k+1][j])
						dp[i][j] = 1;
				}
#endif
				}
			}
		}
#if 0
		for (int i = 0 ; i < s.size() ; i++){
			for (int j = 0 ; j < s.size() ; j++)
				cout << dp[i][j] <<" ";
			cout <<endl;
		}
#endif
		return dp[0][s.size()-1];
        }
	bool isValid(string s, int i, int j){
		if ( (s[i]=='(' && s[j]==')') ||
		     (s[i]=='*' && s[j]==')') ||
		     (s[i]=='(' && s[j]=='*') ||
		     (s[i]=='*' && s[j]=='*')   )
			return true;
		return false;
	}
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	Solution sol;
	int ret;
	ret = sol.checkValidString("(*()()())**(())");
	cout << ret << endl;


	return 0;
}

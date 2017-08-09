#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	int ret;
	public:
	int longestIncreasingPath(vector<vector<int>>& matrix){
		vector< vector<int> > dp(matrix.size() , vector<int>(matrix[0].size(), 0));
		ret = 0;
		for (int i = 0 ; i < matrix.size() ; i++){
			for (int j = 0 ; j < matrix[0].size() ; j++){
				if (!dp[i][j])
					dfs(i, j , matrix, dp);
			}
		}
		for (int i = 0 ; i < matrix.size() ; i++){
			for (int j = 0 ; j < matrix[0].size() ; j++){
					cout << dp[i][j] << " ";
			}
			cout << endl;
		}

		return ret;
	}

	int dfs(int row, int col, vector<vector<int> >& matrix, vector<vector<int> >& dp)
	{
		if (dp[row][col])
			return dp[row][col];
		int nr, nc;
		int currmax = 1;
		int direct[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
		for (int i = 0 ; i < 4 ; i++){
			nr = row + direct[i][0];
			nc = col + direct[i][1];
			if ( nr>= 0 && nr < matrix.size() && nc >=0 && nc < matrix[0].size()){
				if (matrix[nr][nc] > matrix[row][col]){
					int ret = dfs(nr,nc, matrix, dp);
					currmax = max(currmax, ret + 1);
				}
			}
		}
		dp[row][col] = currmax;
		ret = max(currmax, ret);
		return dp[row][col];
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
#if 1
	int A[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
//	int A[] = {1,2,3,4,5};
	int B[] = {3,2,6};
	int C[] = {2,2,1};
#endif
#if 0
	int A[] = {5};
	int B[] = {3};
	int C[] = {2};
#endif
	genVector(da, A);
//	genVector(db, B);
//	genVector(dc, C);
	vector<vector<int> > mm;
	mm.push_back(da);
	//mm.push_back(db);
	//mm.push_back(dc);
	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret = sol.longestIncreasingPath(mm);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

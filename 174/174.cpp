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
	public:
	int calculateMinimumHP(vector<vector<int>>& dungeon){
		int minHp = INT_MAX;
		int m = dungeon.size();
		int n = dungeon[0].size();
		vector<vector<int>> mindp(m, vector<int>(n,0));
		int sum = 0;
		for (int i = 0 ; i < n ; i++){
			sum += dungeon[0][i];
			minHp = min(minHp, sum);
			mindp[0][i] = sum;
		}
		sum = 0;
		for (int i = 0 ; i < m ; i++){
			sum += dungeon[i][0];
			minHp = min(minHp, sum);
			mindp[i][0] = sum;
		}
		for (int i = 1 ; i < m ; i++){
			for (int j = 1 ; j < n ; j++){
				mindp[i][j] = min(mindp[i-1][j],mindp[i][j-1]) + dungeon[i][j];
				minHp = min(minHp, mindp[i][j]);
			}
		}
		if (minHp >= 0)
			return 1;
		cout << minHp << endl;
		int lo = 1, hi = 0 - minHp + 1;
		while(lo <= hi){
			int mid = lo + (hi-lo)/2;
			if (canPass(mid,dungeon))
				hi = mid -1;
			else
				lo = mid + 1;
			cout << "lo:"<< lo  << "hi:" << hi << endl;
		}
		return lo;
		
	}
	bool canPass(int hp, vector<vector<int>>& dd){
		vector<vector<int>> dp(dd.size(), vector<int>(dd[0].size(), 0));
		if (hp + dd[0][0] <=0)
			return false;
		int sum = hp;
		for (int i = 0 ; i < dd[0].size() ; i++){
			sum += dd[0][i];
			dp[0][i] = sum;
			if (sum <= 0)
				break;
		}
		sum = hp;
		for (int i = 0 ; i < dd.size() ; i++){
			sum += dd[i][0];
			dp[i][0] = sum;
			if (sum <= 0)
				break;
		}
		for (int i = 1 ; i < dd.size() ; i++){
			for(int j = 1 ; j < dd[0].size() ; j++){
				if (dp[i-1][j] > 0 && dp[i][j-1] > 0){
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + dd[i][j];
				} else if (dp[i-1][j] > 0){
					dp[i][j] = dp[i-1][j] + dd[i][j];
				} else if (dp[i][j-1] > 0){
					dp[i][j] = dp[i][j-1] + dd[i][j];
				} else
					dp[i][j] = 0;
			}
		}
		
		bool pass= dp[dd.size()-1][dd[0].size()-1] > 0;
		cout << hp << "pass:" << pass << endl;
		for (int i = 0 ; i < dp.size() ; i++){
			for (int j = 0 ; j < dp[0].size() ; j++)
				cout << dp[i][j] << " ";
			cout << endl;
		}
			cout << endl;
			cout << endl;
		return pass;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {3,-20,30};
	int B[] = {-3,4,0};
	int C[] = {10,30,-5};
	genVector(da, A);
	genVector(db, B);
	genVector(dc, C);
	vector<vector<int>> board;
	board.push_back(da);
	board.push_back(db);
//	board.push_back(dc);
	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret = sol.calculateMinimumHP(board);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

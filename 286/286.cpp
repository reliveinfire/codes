#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#if 0
class Solution {
	public:
	void wallsAndGates(vector<vector<int> >& board){
			int ret = 0;
			if (board.empty())
				return;
			int m = board.size(), n = board[0].size();
			vector<vector<bool> > visit(m , vector<bool>(n, false));
			queue< pair<int,int> > qu;
			int direct[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
			for (int i = 0 ; i < m ; i++){
				for (int j = 0 ; j < n ; j++){
					if (board[i][j] == 0)
						qu.push(pair<int,int>(i,j));
				}
			}

			while(!qu.empty()){
				int ni,nj;				
				pair<int,int> tmp = qu.front();qu.pop();
				for (int k = 0 ; k < 4 ; k++){
					ni = tmp.first + direct[k][0];
					nj = tmp.second + direct[k][1];
					if ( ni >= 0 && ni <m && nj >=0 
							&& nj <n && board[ni][nj] != -1){
						if (board[ni][nj] > board[tmp.first][tmp.second] + 1){
						board[ni][nj] = board[tmp.first][tmp.second] + 1;
						pair<int,int> one(ni,nj);
						qu.push(one);
						}
					}
				}


			}
			return;
		}
};
#else
class Solution {
	public:
		void wallsAndGates(vector<vector<int> >& board){
			int ret = 0;
			if (board.empty())
				return;
			int m = board.size(), n = board[0].size();
			vector<vector<bool> > visit(m , vector<bool>(n, false));
			for (int i = 0 ; i < m ; i++){
				for (int j = 0 ; j < n ; j++){
					if (board[i][j] == 0)
						dfs(board, pair<int,int>(i,j));
				}
			}


			return;
		}
	void dfs(vector<vector<int> >& board, pair<int,int> tmp){
			int direct[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
			for (int k = 0 ; k < 4 ; k++){
				int ni = tmp.first + direct[k][0];
				int nj = tmp.second + direct[k][1];
				if ( ni >= 0 && ni <board.size() && nj >=0 
						&& nj <board[0].size() && board[ni][nj] != -1){
					if (board[ni][nj] > board[tmp.first][tmp.second] + 1){
						board[ni][nj] = board[tmp.first][tmp.second] + 1;
						dfs(board, pair<int,int>(ni,nj));
					}
				}
			}
			return;
	}
};
#endif
 
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
#if 0
	char A[] = {'X','X','X','X'};
	char B[] = {'X','O','O','X'};
	char C[] = {'X','X','O','X'};
	char D[] = {'X','O','X','X'};
#else
	int A[] = {INT_MAX,      -1,       0, INT_MAX};
	int B[] = {INT_MAX, INT_MAX, INT_MAX,      -1};
	int C[] = {INT_MAX,      -1, INT_MAX,      -1};
	int D[] = {      0,      -1, INT_MAX, INT_MAX};
#endif
	vector< vector<int> > board;
	
	genVector(da, A);
	genVector(db, B);
	genVector(dc, C);
	genVector(dd, D);
	board.push_back(da);
	board.push_back(db);
	board.push_back(dc);
	board.push_back(dd);
	Solution sol;
	int ret;
	sol.wallsAndGates(board);
	for (int i = 0 ; i < board.size() ; i++){
		for (int j = 0 ; j < board[0].size() ; j++){
			cout << " " << board[i][j];
		}
		cout << endl;
	}

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

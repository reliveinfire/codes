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

class Solution {
	public:
		void solve(vector<vector<char> >& board){
			int ret = 0;
			if (board.empty())
				return;
			int m = board.size(), n = board[0].size();
			vector<vector<bool> > visit(m , vector<bool>(n, false));
			queue< pair<int,int> > qu;
			int direct[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

			for (int i = 0 ; i < n ; i++){
				if (board[0][i] == 'O'){
					pair<int,int> tmp(0,i);
					visit[0][i] =true;
					qu.push(tmp);
				}
				if (board[m-1][i]== 'O'){
					pair<int,int> tmp(m-1,i);
					visit[m-1][i] =true;
					qu.push(tmp);
				}
			}
			for (int i = 0 ; i < m ; i++){
				if (board[i][0] == 'O'){
					pair<int,int> tmp(i,0);
					visit[i][0] =true;
					qu.push(tmp);
				}
				if (board[i][n-1] == 'O'){
					pair<int,int> tmp(i,n-1);
					visit[i][n-1] =true;
					qu.push(tmp);
				}
			}
			while(!qu.empty()){
				int ni,nj;				
				pair<int,int> tmp = qu.front();qu.pop();
				for (int k = 0 ; k < 4 ; k++){
					ni = tmp.first + direct[k][0];
					nj = tmp.second + direct[k][1];
					if ( ni >= 0 && ni <m && nj >=0 
							&& nj <n && !visit[ni][nj] &&
							board[ni][nj] == 'O'){
						pair<int,int> one(ni,nj);
						visit[ni][nj] = true;
						qu.push(one);
					}
				}


			}
			for (int i = 0 ; i < m ; i++){
				for (int j = 0 ; j < n ; j++){
					if (board[i][j] == 'O' && !visit[i][j])
						board[i][j] = 'X';
				}
			}
			return;
		}
};
 
#define genVector(data, array) vector<char> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
#if 0
	char A[] = {'X','X','X','X'};
	char B[] = {'X','O','O','X'};
	char C[] = {'X','X','O','X'};
	char D[] = {'X','O','X','X'};
#else
	char A[] = {'X','X','X'};
	char B[] = {'X','O','X'};
	char C[] = {'X','X','X'};
#endif
	vector< vector<char> > board;
	
	genVector(da, A);
	genVector(db, B);
	genVector(dc, C);
	board.push_back(da);
	board.push_back(db);
	board.push_back(dc);
//	board.push_back(dd);
	Solution sol;
	int ret;
	sol.solve(board);
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

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
class MPoint
{
	public:
	int x;
	int y;
	MPoint(int ix, int iy){x = ix;y = iy;}
};
class Solution {
	public:
	vector<vector<char> > updateBoard(vector<vector<char> >& board, vector<int>& click){
		int m = board.size();
		int n = board[0].size();
		int around[8][2] = { {-1,-1},{-1,0},{-1,1},
				    {0,-1},{0,1},
				   {1,-1},{1,0},{1,1}};
		MPoint p(click[0],click[1]);
		queue<MPoint> qq;
		qq.push(p);
		while(!qq.empty()){
			MPoint handle = qq.front();
			stringstream ss;
			ss.clear();
			int hx = handle.x;
			int hy = handle.y;
			int count = 0;
			qq.pop();
			if (board[hx][hy] == 'M'){
				board[hx][hy]= 'X';
				break;
			}
			for (int i = 0 ; i < 8 ; i++){
				int ax = hx + around[i][0];
				int ay = hy + around[i][1];
				if (ax >= 0  && ax < m && ay >=0 && ay < n){
					if (board[ax][ay]=='M'){
						count++;
					}
				}
			}
			ss << count;
			if (count == 0){
				board[hx][hy] = 'B';
				for (int i = 0 ; i < 8 ; i++){
					int dx = hx + around[i][0];
					int dy = hy + around[i][1];
					if (dx >= 0 && dx < m && dy>=0 && dy <n){
						if (board[dx][dy]=='E'){
							MPoint tmp(dx,dy);
							qq.push(tmp);
						}
					}
				}
			}
			else {
				board[hx][hy] = ss.str()[0];
			}
			
		}
		return board;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
#if 0
	char cb[][5] = {
			{'E','E','E','E','E'},
			{'E','E','M','E','E'},
			{'E','E','E','E','E'},
			{'E','E','E','E','E'}};
	vector< vector<char> > board;
	vector<char> tmp;
	for (int i = 0 ; i < 4 ; i++){
		for (int j = 0 ; j < 5 ; j++){
			tmp.push_back(cb[i][j]);
		}
		board.push_back(tmp);
		tmp.clear();
	}
	
	for (int i = 0 ; i < 4 ; i++){
		for (int j = 0 ; j < 5 ; j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
#else
	char cb[][8] = {
			{'E','M','M','2','B','B','B','B'},
			{'E','E','M','2','B','B','B','B'},
			{'E','E','2','1','B','B','B','B'},
			{'E','M','1','B','B','B','B','B'},
			{'1','2','2','1','B','B','B','B'},
			{'B','1','M','1','B','B','B','B'},
			{'B','1','1','1','B','B','B','B'},
			{'B','B','B','B','B','B','B','B'},
			};
	vector< vector<char> > board;
	vector<char> tmp;
	for (int i = 0 ; i < 8 ; i++){
		for (int j = 0 ; j < 8 ; j++){
			tmp.push_back(cb[i][j]);
		}
		board.push_back(tmp);
		tmp.clear();
	}
	
	for (int i = 0 ; i < 8 ; i++){
		for (int j = 0 ; j < 8 ; j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
#endif
	vector<int> input;
	input.push_back(0);
	input.push_back(0);
	Solution sol;
	vector< vector<char> >  ret = sol.updateBoard(board,input);
	
	for (int i = 0 ; i < 8 ; i++){
		for (int j = 0 ; j < 8 ; j++){
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}

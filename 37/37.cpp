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
	bool isdone;
	void solveSudoku(vector<vector<char>>& board){
		vector< set<char> > rows(9);
		vector< set<char> > cols(9);
		vector< set<char> > blocks(9);
		isdone = false;
		for (int i = 0 ; i < 9 ; i++){
			for (int j = 0 ; j < 9 ; j++){
				if (board[i][j] != '.' ){
					rows[i].insert(board[i][j]);
					cols[j].insert(board[i][j]);
					blocks[(i/3)*3+j/3].insert(board[i][j]);
				}
			}
		}
		helper(board, 0, rows, cols, blocks);
		return;
	}
	void helper(vector<vector<char> >& board, int curr,
			   vector<set<char> >& rows, vector<set<char> >& cols, vector<set<char> >& blocks)
	{
		int row = curr / 9;
		int col = curr % 9;
		if (curr > 80){
			isdone = true;
			return;
		}
		if (board[row][col] != '.')
			helper(board, curr+1, rows, cols, blocks);
		else{
			for (int i = 1 ; i <= 9 ; i++){
				char cc = (char)(i + '0');
				if (rows[row].count(cc) == 0 &&
				    cols[col].count(cc) == 0 &&
				    blocks[row/3*3 + col/3].count(cc) ==0){
				    	 rows[row].insert(cc);
					 cols[col].insert(cc);
					 blocks[row/3*3 + col/3].insert(cc);
					 board[row][col] =  cc;
					 helper(board, curr+1, rows, cols, blocks);
					 if (isdone)
					 	break;
					 board[row][col] = '.';
				    	 rows[row].erase(cc);
					 cols[col].erase(cc);
					 blocks[row/3*3 + col/3].erase(cc);
				  }
			}
		}
		return;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	char board[9][9] = {
	{'5','3','.',  '.','7','.',  '.','.','.'},
	{'6','.','.',  '1','9','5',  '.','.','.'},
	{'.','9','8',  '.','.','.',  '.','6','.'},
	{'8','.','.',  '.','6','.',  '.','.','3'},
	{'4','.','.',  '8','.','3',  '.','.','1'},
	{'7','.','.',  '.','2','.',  '.','.','6'},
	{'.','6','.',  '.','.','.',  '2','8','.'},
	{'.','.','.',  '4','1','9',  '.','.','5'},
	{'.','.','.',  '.','8','.',  '.','7','9'}};
	
	vector<vector<char> > mm;
	for (int i = 0 ; i < 9 ; i++){
		vector<char> vv;
		vv.clear();
		for (int j = 0 ; j < 9 ; j++){
			vv.push_back(board[i][j]);
		}
		mm.push_back(vv);
	}

	for (int i = 0 ; i < 9 ; i++){
		for (int j = 0 ; j < 9 ; j++){
			cout << " " << mm[i][j];
		}
		cout << endl;
	}
	Solution sol;
	sol.solveSudoku(mm);
	cout << "ans\n";
	for (int i = 0 ; i < 9 ; i++){
		for (int j = 0 ; j < 9 ; j++){
			cout << " " << mm[i][j];
		}
		cout << endl;
	}


	return 0;
}

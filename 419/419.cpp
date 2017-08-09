#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <sstream>

using namespace std;

class Solution {
	public:
		int countBattleships(vector<vector<char> >& board) {
			int count = 0;
			if (board.empty())
				return count;
			for (int i = 0 ; i< board.size() ; i++){
				for(int j = 0 ; j < board[i].size() ; j++) {
					if(board[i][j] == 'X'){
						if (i==0 && j==0){
							count++;
						} else if (i==0 && j!=0){
							if(board[i][j-1] != 'X')
								count++;
						} else if(i!=0 && j==0 ){
							if(board[i-1][j] != 'X')
								count++;
						} else {
							if(board[i][j-1] != 'X'
									&& board[i-1][j]!='X')
								count++;
						}
					}
				}
			}
			return count;
		}
};


int main()
{
	int ret;
	int test[] = {1,2,3};
	vector< vector<char> > data;
	Solution sol;
	cout << sol.countBattleships(data);

	return 0;
}

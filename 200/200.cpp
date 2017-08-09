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
	int numIslands(vector<vector<char> >& grid){
		int ret = 0;
		if (grid.empty())
			return ret;
		int m = grid.size(), n = grid[0].size();
		vector<vector<bool> > visit(m , vector<bool>(n, false));
		queue< pair<int,int> > qu;
		int direct[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
		for (int i = 0 ; i < m ; i++){
			for (int j = 0 ; j < n ; j++){
				if (grid[i][j] == '1' && !visit[i][j]){
					ret++;
					pair<int,int> tmp;
					tmp.first = i;tmp.second = j;
					qu.push(tmp);
					visit[tmp.first][tmp.second] = true;
					while(!qu.empty()){
						int ni,nj;
						tmp = qu.front();qu.pop();
						for (int k = 0 ; k < 4 ; k++){
							ni = tmp.first + direct[k][0];
							nj = tmp.second + direct[k][1];
							if ( ni >= 0 && ni <m && nj >=0 
								&& nj <n && !visit[ni][nj] &&
								grid[ni][nj] == '1'){
								pair<int,int> one;
								one.first = ni;
								one.second = nj;
								qu.push(one);
								visit[ni][nj] = true;
							}
						}
					}
				}
			}
		}
		return ret;
	}
};
 
#define genVector(data, array) vector<char> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	char A[] = {'1','1','0','0','0'};
	char B[] = {'1','1','0','0','0'};
	char C[] = {'0','0','1','0','0'};
	char D[] = {'0','0','0','1','1'};
	vector< vector<char> > grid;
	
	genVector(da, A);
	genVector(db, B);
	genVector(dc, C);
	genVector(dd, D);
	grid.push_back(da);
	grid.push_back(db);
	grid.push_back(dc);
	grid.push_back(dd);
	Solution sol;
	int ret;
	ret = sol.numIslands(grid);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

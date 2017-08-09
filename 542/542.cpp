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
class Solution {
	public:
	vector<vector<int> > updateMatrix(vector<vector<int> >& matrix){
		vector< pair<int,int> > zeros;
		queue< pair<int,int> > qu;
		int direct[4][2]= {{-1,0},{0,-1},{1,0},{0,1}};
		if (matrix.empty())
			return matrix;
		int m = matrix.size();
		int n = matrix[0].size();
		for (int i = 0 ; i < m ; i++){
			for (int j = 0 ; j < n ; j++){
				pair<int,int> tmp;
				if (matrix[i][j] == 0){
					tmp.first = i;
					tmp.second= j;
					zeros.push_back(tmp);
				} else {
					matrix[i][j] = INT_MAX;
				}
			}
		}
		for (int i = 0 ; i < zeros.size() ; i++){
			qu.push(zeros[i]);
		}
		int row, col;
		while(!qu.empty()){
			pair<int,int> tmp = qu.front();
			qu.pop();
			row = tmp.first;
			col = tmp.second;
			for (int i = 0 ; i < 4; i++){
				int nr = row + direct[i][0];
				int nc = col + direct[i][1];
				if (nr >= 0 && nr < m && nc >= 0 && nc < n){
					if (matrix[row][col]+1 < matrix[nr][nc]){
						matrix[nr][nc] = matrix[row][col] + 1;
						tmp.first = nr;
						tmp.second = nc;
						qu.push(tmp);
					}
				}
			}
		}
		return matrix;	
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	int tt[3][3] = {{0,0,0},
			{0,1,0},
			{1,1,1}};
	vector<int> row;
	vector< vector<int> >mm;
	for (int i = 0 ; i < 3 ; i++){
		for (int j = 0 ; j < 3 ; j++){
			row.push_back(tt[i][j]);
		}
		mm.push_back(row);
		row.clear();
	}
	for (int i = 0 ; i < 3 ; i++){
		for (int j = 0 ; j < 3 ; j++){
			cout << mm[i][j] << " ";
		}
		cout << endl;
	}
		cout << endl;
	vector< vector<int> > result;
	Solution sol;
	 result = sol.updateMatrix(mm);
	
	for (int i = 0 ; i < 3 ; i++){
		for (int j = 0 ; j < 3 ; j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

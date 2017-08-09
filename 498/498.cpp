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
	vector<int> findDiagonalOrder(vector<vector<int> >& matrix){
		vector<int> result;
		if(matrix.empty()) {
			return result;
		}
		if (matrix[0].empty())
			return result;
		int m = matrix.size();
		int n = matrix[0].size();
		int direct[2][2] = {{-1,1}, //up,right
				    {1,-1}};//down, left
		int row = 0, col = 0, dd = 0;
		int nr,nc;
		bool turn;
		for (int i = 0 ; i < m*n ; i++){
			result.push_back(matrix[row][col]);
			turn = false;
			nr = row + direct[dd][0];
			nc = col + direct[dd][1];
			if (nr < 0) {
				nr = row;
				turn = true;
			}
			if (nc < 0){
				nc = col;
				turn = true;
			}
			if (nr > m - 1){
				nr = row;
				nc = col + 1;
				turn = true;
			}
			if (nc > n - 1){
				nc = col;
				nr = row + 1;
				turn = true;
			}
			if (turn)
				dd = dd ^ 1;
			row = nr;
			col = nc;
		}
		return result; 
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {1,2,3};
	int B[] = {4,5,6};
	int C[] = {7,8,9};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	genVector(dc, C);
	vector<vector<int> > mm;
	mm.push_back(da);
	mm.push_back(db);
	mm.push_back(dc);
	vector<vector<int> > ma;
	Solution sol;
	ret_vec = sol.findDiagonalOrder(ma);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

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

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
    	for (int i = 0 ; i < matrix.size() ; i++){
		int sum = 0;
		vector<int> row;
		row.clear();
		for (int j = 0 ; j < matrix[0].size() ; j++){
			sum += matrix[i][j];
			if (i != 0 ){
				row.push_back(sum + preSum[i-1][j]);
			} else {
				row.push_back(sum);
			}
		}
		preSum.push_back(row);
	}

    }

    int sumRegion(int row1, int col1, int row2, int col2) {
    		if (row1 == 0 && col1 == 0){
			return preSum[row2][col2];
		} else if (row1 == 0){
			return preSum[row2][col2] - preSum[row2][col1-1];
		} else if (col1 == 0){
			return preSum[row2][col2] - preSum[row1 - 1][col2];
		} else {
			return preSum[row2][col2] + preSum[row1-1][col1-1]
				-preSum[row2][col1-1] - preSum[row1 -1 ][col2];
		}
    }
private:
	vector<vector<int> > preSum;
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {3,0,1,4};
	int B[] = {5,6,3,2};
	int C[] = {1,2,0,1};
	genVector(da, A);
	genVector(db, B);
	genVector(dc, C);
	vector<vector<int> >mm;
	mm.push_back(da);
	mm.push_back(db);
	mm.push_back(dc);
	NumMatrix nm(mm);
	int ret;
	cout << nm.sumRegion(0,0,1,1) << "\n";
	cout << nm.sumRegion(1,2,2,3) << "\n";


	return 0;
}

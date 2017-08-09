#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <unordered_set>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Interval
{
	int start;
	int end;
}
class Solution {
	public:
	bool canAttendMeetings(vector<Interval>& intervals){
		
	}
};
class Vector2D {
	public:
	Vector2D(vector<vector<int>>& matrix){
		mm = matrix;
		int row = 0, col = 0;
		row = nextRow();
		begin_row = row;
		begin_col = col;
	}
	bool hasNext(){
		return row < matrix.size();
	}
	int next(){
		int ret = matrix[row][col];
		col++;
		if (col == matrix[row].size()){
			row = nextRow();
			col = 0;
		}
		return ret;
	}
	}
	private:
		int nextRow(){
			while(row<matrix.size() && matrix[row].empty()){
				row++;
			}
			return row;
		}
		vector<vector<int>> mm;
		int row;
		int col;
}

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret = sol.
	ret_vec = sol.
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

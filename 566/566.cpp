#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
using namespace std;
#include "../helpers.cpp"
vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};


class Solution {
	public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c){
		int row = nums.size();
		int col = nums[0].size();
		cout << row <<"  r:r " << col << endl;
		if (row*col != r*c)
			return {{}};
		vector<vector<int>> ans(nums.size(), vector<int>(nums[0].size()));
		int ir = 0 , ic = 0;
		for (int i = 0 ; i < row ; i++){
			for (int j = 0 ; j < col ; j++){
				cout << i << ":" << j << endl;
				ans[ir][ic] = nums[i][j];
				ic++;
				if (ic == c){
					ir++;
					ic = 0;
				}
			}
		}
		return ans;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<vector<int>> A = {{1,2},{3,4}};
	vector<vector<int>> ret_vec;
	Solution sol;
	ret_vec = sol.matrixReshape(A, 1,4);


	return 0;
}

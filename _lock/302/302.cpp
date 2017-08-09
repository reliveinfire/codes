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
struct Range
{
	int max_x;
	int min_x;
	int max_y;
	int min_y;
	Range(int x1, int x2, int y1, int y2):max_x(x1), min_x(x2),max_y(y1),min_y(y2){}
};
class Solution {
	public:
	int smallestRect(vector<vector<int>>& grid, int x, int y){
		Range r(x,x,y,y);
		dfs(grid, x, y, r);
		return (r.max_x - r.min_x + 1) * (r.max_y - r.min_y + 1);
	}
	void dfs(vector<vector<int>>& grid, int cx, int cy, Range& r){
		if (cx < 0 || cx >= grid.size()||
				cy < 0 || cy >= grid[0].size() || !grid[cx][cy])
			return;
		grid[cx][cy] = 0;
		if (cx > r.max_x)
			r.max_x = cx;
		if (cx < r.min_x)
			r.min_x = cx;
		if (cy > r.max_y)
			r.max_y = cy;
		if (cy < r.min_y)
			r.min_y = cy;
		dfs(grid, cx+1, cy, r);
		dfs(grid, cx-1, cy, r);
		dfs(grid, cx, cy+1, r);
		dfs(grid, cx, cy-1, r);
		return;
	}

};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<vector<int>> grid = {
		{0,0,1,0,0},
		{0,1,1,0,1},
		{0,1,1,1,1},
		{0,1,0,0,0}
					};
	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret = sol.smallestRect(grid, 0,2);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}

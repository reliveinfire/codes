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
class Line
{
	public:
	int x;
	int y;
	int tMin;
	int tMax;
	Line(int x,int y, int tMin, int tMax): x(x), y(y), tMin(tMin), tMax(tMax){}
};
class Solution {
	public:
	bool isSelfCrossing(vector<int>& x){
		bool ret = false;
		int curX = 0, curY = 0, nextX, nextY;
		int direct[4][2] =  {{0,1},{-1,0},{0,-1},{1,0}};
		List<Line> lines;
		for (int i = 0 ; i < x.size() ; i++){
			int di = i % 4;
			Line tmp;
			struct
			nextX = curX + direct[di][0] * x[i];
			nextY = curY + direct[di][1] * x[i];
			
			if (curX == nextX){
				tmp.x = curX;
				tmp.y = 0;
				tmp.tMin = min(curY, nextY);
				tmp.tMax = max(curY, nextY);
			} else {
				tmp.x = 0;
				tmp.y = curY;
				tmp.tMin = min(curX, nextX);
				tmp.tMax = max(curX, nextX);
			}
			if (i < 3){
				lines.insert(tmp);
			} else {
				ret = checkCross(tmp, lines);
				if (ret)
					return ret;
				removeUseless(tmp, lines);
			}
			curX = nextX;
			curY = nextY;
		}

		return ret;
	}
	bool checkCross(Line target, List<Line>& lines){
		for (List<Line>::iterator iter = lines.begin() ; iter!=lines.end() ; iter++){
			if ((target.x && iter->y)){
				if (target.x >= iter->tMin && target.x <= iter->tMax &&
					iter->y >= target.tMin && iter->y <= target.tMax)		
						return true;
			} else if (target.y && iter->x){
				if (target.y >= iter->tMin && target.y <= iter->tMax &&
					iter->x >= target.tMin && iter->x <= target.tMax)		
						return true;
			}
		}
		return false;
	}
	void removeUseless(Line target, List<Line>& lines){
		
	}
};

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

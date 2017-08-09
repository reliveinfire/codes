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
	vector<vector<int>> generateMatrix(int nn){
		vector<vector<int>> tmp;
		if (nn==0)
			return tmp;
		vector<vector<int>> ans(nn, vector<int>(nn));
		int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0}};
		int m = nn, n = nn;
		int rowU = m, rowL = 0;
		int colU = n, colL = 0;
		int di = 0, cr = 0, cc = 0;
		int nr, nc;
		int curr = 1;
		while(true){
			ans[cr][cc] = curr;
			curr++;
			if (curr > nn*nn)
				break;
			nr = cr + direct[di][0];
			nc = cc + direct[di][1];
			if ( nr >= rowU || nr < rowL || nc >= colU || nc < colL){
				if (di == 0) rowL++;
				else if (di == 1) colU--;
				else if (di == 2) rowU--;
				else if (di == 3) colL++;
				di = (di + 1)%4;
				cr += direct[di][0];
				cc += direct[di][1];
			} else {
				cr = nr;
				cc = nc;
			}
		}
		return ans;
		
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {1,2,3};
	int B[] = {4,5,6};
	int C[] = {7,8,9};
	genVector(da, A);
	genVector(db, B);
	genVector(dc, C);
	vector<vector<int>> mm;
	mm.push_back(da);
	mm.push_back(db);
	mm.push_back(dc);
	Solution sol;

	cout <<endl;

	return 0;
}
